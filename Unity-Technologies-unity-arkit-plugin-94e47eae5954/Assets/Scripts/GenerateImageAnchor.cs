using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.iOS;

public class GenerateImageAnchor : MonoBehaviour {

    public Vector3 shinkawaPos;
    public Vector3 shinkawaScale;
    public Vector3 deskPos;
    public Vector3 deskScale;
    public Vector3 autdPos;
    public Vector3 autdScale;


    public Material material;

    private Material deskMaterial;
    private Material autdMaterial;

	[SerializeField]
	private ARReferenceImage referenceImage;

	[SerializeField]
	public GameObject prefabToGenerate1;   // shinkawaを入れる
    [SerializeField]
    public GameObject prefabToGenerate2;   // deskを入れる
    [SerializeField]
    public GameObject prefabToGenerate3;   // autdを入れる

    [SerializeField]
    RuntimeAnimatorController runtimeAnimatorController;
    [SerializeField]
    Avatar avatar;
    Animator animator;


    public GameObject shinkawa;
    public GameObject autd;
    public GameObject desk;

    MeshRenderer deskMeshRenderer;
    MeshRenderer autdMeshRenderer;

	// Use this for initialization
	void Start () {
		UnityARSessionNativeInterface.ARImageAnchorAddedEvent += AddImageAnchor;
		UnityARSessionNativeInterface.ARImageAnchorUpdatedEvent += UpdateImageAnchor;
		UnityARSessionNativeInterface.ARImageAnchorRemovedEvent += RemoveImageAnchor;

        shinkawaPos = new Vector3(0, 0, 0);
        shinkawaScale = new Vector3(1,1,1);
        deskPos = new Vector3(0, 0, 0);
        deskScale = new Vector3(1, 1, 1);
        autdPos = new Vector3(0, 0, 0);
        autdScale = new Vector3(1, 1, 1);

    }

	void AddImageAnchor(ARImageAnchor arImageAnchor)
	{
		Debug.LogFormat("image anchor added[{0}] : tracked => {1}", arImageAnchor.identifier, arImageAnchor.isTracked);
		if (arImageAnchor.referenceImageName == referenceImage.imageName) {
			Vector3 position = UnityARMatrixOps.GetPosition (arImageAnchor.transform);
			Quaternion rotation = UnityARMatrixOps.GetRotation (arImageAnchor.transform);

			shinkawa = Instantiate<GameObject> (prefabToGenerate1, position, rotation);    // shinkawaをinstantiate
            desk = Instantiate<GameObject> (prefabToGenerate2, position, rotation);    // deskをinstantiate
            autd = Instantiate<GameObject>(prefabToGenerate3, position, rotation);    // autdをinstantiate


            deskMeshRenderer = desk.GetComponent<MeshRenderer>();
            autdMeshRenderer = autd.GetComponent<MeshRenderer>();

            // animation関連の処理
            shinkawa.AddComponent<Animator>();
            animator = shinkawa.GetComponent<Animator>();
            animator.runtimeAnimatorController = runtimeAnimatorController;
            animator.avatar = avatar;
            animator.enabled = true;
            animator.Play("state1");

        }
    }

	void UpdateImageAnchor(ARImageAnchor arImageAnchor)
	{
        
		Debug.LogFormat("image anchor updated[{0}] : tracked => {1}", arImageAnchor.identifier, arImageAnchor.isTracked);
		if (arImageAnchor.referenceImageName == referenceImage.imageName) {
            if (arImageAnchor.isTracked)
            {
                if (!shinkawa.activeSelf)
                {
                    shinkawa.SetActive(true);
                }
                shinkawa.transform.position = UnityARMatrixOps.GetPosition(arImageAnchor.transform) + shinkawaPos;
                shinkawa.transform.rotation = UnityARMatrixOps.GetRotation(arImageAnchor.transform);
                shinkawa.transform.Rotate(new Vector3(0,90,90));
                shinkawa.transform.localScale = shinkawaScale;

                if (!desk.activeSelf)
                {
                    desk.SetActive(true);
                }
                desk.transform.position = UnityARMatrixOps.GetPosition(arImageAnchor.transform) + deskPos;
                desk.transform.rotation = UnityARMatrixOps.GetRotation(arImageAnchor.transform);
                desk.transform.Rotate(new Vector3(0, 0, 90));
                desk.transform.localScale = deskScale;
                deskMeshRenderer.material = material;

                if (!autd.activeSelf)
                {
                    autd.SetActive(true);
                }
                autd.transform.position = UnityARMatrixOps.GetPosition(arImageAnchor.transform) + autdPos;
                autd.transform.rotation = UnityARMatrixOps.GetRotation(arImageAnchor.transform);
                autd.transform.Rotate(new Vector3(0, 90, 90));
                autd.transform.localScale = autdScale;
                autdMeshRenderer.material = material;
            }
            else if (shinkawa.activeSelf || desk.activeSelf || autd.activeSelf)
            {
                shinkawa.SetActive(false);
                desk.SetActive(false);
                autd.SetActive(false);
            }
        }

	}

	void RemoveImageAnchor(ARImageAnchor arImageAnchor)
	{
		Debug.LogFormat("image anchor removed[{0}] : tracked => {1}", arImageAnchor.identifier, arImageAnchor.isTracked);
		if (shinkawa || desk || autd) {
			Destroy (shinkawa);
            Destroy(desk);
            Destroy(autd);
        }

	}

	void OnDestroy()
	{
		UnityARSessionNativeInterface.ARImageAnchorAddedEvent -= AddImageAnchor;
		UnityARSessionNativeInterface.ARImageAnchorUpdatedEvent -= UpdateImageAnchor;
		UnityARSessionNativeInterface.ARImageAnchorRemovedEvent -= RemoveImageAnchor;

	}

	// Update is called once per frame
	void Update () {
        
    }
}
