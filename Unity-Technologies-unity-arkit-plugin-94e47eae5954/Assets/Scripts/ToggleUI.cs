using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ToggleUI : MonoBehaviour
{

    [SerializeField]
    GameObject plusxButton;
    [SerializeField]
    GameObject minusxButton;
    [SerializeField]
    GameObject plusyButton;
    [SerializeField]
    GameObject minusyButton;
    [SerializeField]
    GameObject pluszButton;
    [SerializeField]
    GameObject minuszButton;
    [SerializeField]
    GameObject bigButton;
    [SerializeField]
    GameObject smallButton;

    bool isActivated = true;

    /// ボタンをクリックした時の処理
    public void OnClick()
    {
        if(isActivated)
        {
            plusxButton.SetActive(false);
            minusxButton.SetActive(false);
            plusyButton.SetActive(false);
            minusyButton.SetActive(false);
            pluszButton.SetActive(false);
            minuszButton.SetActive(false);
            bigButton.SetActive(false);
            smallButton.SetActive(false);
        }
        else
        {
            plusxButton.SetActive(true);
            minusxButton.SetActive(true);
            plusyButton.SetActive(true);
            minusyButton.SetActive(true);
            pluszButton.SetActive(true);
            minuszButton.SetActive(true);
            bigButton.SetActive(true);
            smallButton.SetActive(true);
        }
        isActivated = !isActivated;
    }
}



