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

	float x, y, z;

	private void Start()
	{
		generateImageAnchor = manager.GetComponent<GenerateImageAnchor>();
		count = 0;
	}

	public void OnClick()
	{
		// 透明なマテリアルと普通のマテリアルを交互に切り替える.
		if (count == 0)
		{
			generateImageAnchor.desk.GetComponent<Renderer>().material = cutoutMaterial;
			generateImageAnchor.autd.GetComponent<Renderer>().material = cutoutMaterial;
		}
		else
		{
			generateImageAnchor.desk.GetComponent<Renderer>().material = standardMaterial;
			generateImageAnchor.autd.GetComponent<Renderer>().material = standardMaterial;
		}

		count = 1 - count;
	}
}
