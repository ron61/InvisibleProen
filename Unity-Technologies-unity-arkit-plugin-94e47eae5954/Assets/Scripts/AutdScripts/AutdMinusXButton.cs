using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AutdMinusXButton : MonoBehaviour
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
        x = generateImageAnchor.autdPos.x;
        y = generateImageAnchor.autdPos.y;
        z = generateImageAnchor.autdPos.z;
        generateImageAnchor.autdPos = new Vector3(x - 0.1f, y, z);
    }
}
