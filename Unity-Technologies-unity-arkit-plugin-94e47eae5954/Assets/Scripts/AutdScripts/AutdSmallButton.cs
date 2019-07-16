using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AutdSmallButton : MonoBehaviour
{
    [SerializeField]
    GameObject manager;
    GenerateImageAnchor generateImageAnchor;
    float x, y, z;

    private void Start()
    {
        generateImageAnchor = manager.GetComponent<GenerateImageAnchor>();
    }

    public void OnClick()
    {
        generateImageAnchor.autdScale *= 0.95f;
    }
}
