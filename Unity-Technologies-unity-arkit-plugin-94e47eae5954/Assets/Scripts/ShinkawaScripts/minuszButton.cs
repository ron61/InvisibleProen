using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class minuszButton : MonoBehaviour
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
        x = generateImageAnchor.shinkawaPos.x;
        y = generateImageAnchor.shinkawaPos.y;
        z = generateImageAnchor.shinkawaPos.z;
        generateImageAnchor.shinkawaPos = new Vector3(x, y, z - 0.1f);
    }
}
