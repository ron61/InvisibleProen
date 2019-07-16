using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DeskMinusXButton : MonoBehaviour
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
        x = generateImageAnchor.deskPos.x;
        y = generateImageAnchor.deskPos.y;
        z = generateImageAnchor.deskPos.z;
        generateImageAnchor.deskPos = new Vector3(x - 0.1f, y, z);
    }
}
