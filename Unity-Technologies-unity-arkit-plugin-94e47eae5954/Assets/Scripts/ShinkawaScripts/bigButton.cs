using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class bigButton : MonoBehaviour
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
        generateImageAnchor.shinkawaScale *= 1.05f;
    }
}
