using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AutdMinusZButton : MonoBehaviour
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
        generateImageAnchor.autdPos = new Vector3(x, y, z - 0.1f);
    }
}
