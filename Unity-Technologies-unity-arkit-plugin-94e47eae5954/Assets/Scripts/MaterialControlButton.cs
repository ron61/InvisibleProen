using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MaterialControlButton : MonoBehaviour
{
	[SerializeField]
	GameObject manager;
	[SerializeField]
	Material cutoutMaterial;
	[SerializeField]
	Material standardMaterial;

    Material arMaterial;
    int count;
	GenerateImageAnchor generateImageAnchor;
	float x, y, z;

	private void Start()
	{
		generateImageAnchor = manager.GetComponent<GenerateImageAnchor>();
		count = 0;
        arMaterial = generateImageAnchor.material;
	}

	public void OnClick()
	{
		// 透明なマテリアルと普通のマテリアルを交互に切り替える.
		if (count == 0)
		{
			arMaterial = cutoutMaterial;
		}
		else
		{
			arMaterial = standardMaterial;
		}

		count = 1 - count;
	}
}
