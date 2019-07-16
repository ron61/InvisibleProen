using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DeskSmallButton : MonoBehaviour
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
        generateImageAnchor.deskScale *= 0.95f;
    }
}
