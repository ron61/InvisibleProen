using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class startButton : MonoBehaviour
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
        if (generateImageAnchor.animator.enabled == true) return;
        generateImageAnchor.animator.enabled = true;
        generateImageAnchor.animator.Play("state1",0,0.0f);
    }
}
