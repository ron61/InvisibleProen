using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class stopButton : MonoBehaviour
{
    [SerializeField]
    GameObject manager;
    GenerateImageAnchor generateImageAnchor;


    // Start is called before the first frame update
    void Start()
    {
        generateImageAnchor = manager.GetComponent<GenerateImageAnchor>();
    }

    public void OnClick()
    {
        generateImageAnchor.animator.enabled = false;
    }
}
