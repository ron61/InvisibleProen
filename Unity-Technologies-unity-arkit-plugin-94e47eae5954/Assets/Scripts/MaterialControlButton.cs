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

    int count;
	GenerateImageAnchor generateImageAnchor;

	private void Start()
	{
		generateImageAnchor = manager.GetComponent<GenerateImageAnchor>();
		count = 0;
        generateImageAnchor.material = standardMaterial;
	}

	public void OnClick()
	{
		// 透明なマテリアルと普通のマテリアルを交互に切り替える.
		if (count == 0)
		{
            generateImageAnchor.material = cutoutMaterial;
		}
		else
		{
            generateImageAnchor.material = standardMaterial;
		}

		count = 1 - count;
	}
}
