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

    [SerializeField]
    GameObject deskplusxButton;
    [SerializeField]
    GameObject deskminusxButton;
    [SerializeField]
    GameObject deskplusyButton;
    [SerializeField]
    GameObject deskminusyButton;
    [SerializeField]
    GameObject deskpluszButton;
    [SerializeField]
    GameObject deskminuszButton;
    [SerializeField]
    GameObject deskbigButton;
    [SerializeField]
    GameObject desksmallButton;

    [SerializeField]
    GameObject autdplusxButton;
    [SerializeField]
    GameObject autdminusxButton;
    [SerializeField]
    GameObject autdplusyButton;
    [SerializeField]
    GameObject autdminusyButton;
    [SerializeField]
    GameObject autdpluszButton;
    [SerializeField]
    GameObject autdminuszButton;
    [SerializeField]
    GameObject autdbigButton;
    [SerializeField]
    GameObject autdsmallButton;

    [SerializeField]
    GameObject materialButton;
    [SerializeField]
    GameObject startButton;
    [SerializeField]
    GameObject stopButton;


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

            deskplusxButton.SetActive(false);
            deskminusxButton.SetActive(false);
            deskplusyButton.SetActive(false);
            deskminusyButton.SetActive(false);
            deskpluszButton.SetActive(false);
            deskminuszButton.SetActive(false);
            deskbigButton.SetActive(false);
            desksmallButton.SetActive(false);

            autdplusxButton.SetActive(false);
            autdminusxButton.SetActive(false);
            autdplusyButton.SetActive(false);
            autdminusyButton.SetActive(false);
            autdpluszButton.SetActive(false);
            autdminuszButton.SetActive(false);
            autdbigButton.SetActive(false);
            autdsmallButton.SetActive(false);

            materialButton.SetActive(false);
            startButton.SetActive(false);
            stopButton.SetActive(false);
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

            deskplusxButton.SetActive(true);
            deskminusxButton.SetActive(true);
            deskplusyButton.SetActive(true);
            deskminusyButton.SetActive(true);
            deskpluszButton.SetActive(true);
            deskminuszButton.SetActive(true);
            deskbigButton.SetActive(true);
            desksmallButton.SetActive(true);

            autdplusxButton.SetActive(true);
            autdminusxButton.SetActive(true);
            autdplusyButton.SetActive(true);
            autdminusyButton.SetActive(true);
            autdpluszButton.SetActive(true);
            autdminuszButton.SetActive(true);
            autdbigButton.SetActive(true);
            autdsmallButton.SetActive(true);

            materialButton.SetActive(true);
            startButton.SetActive(true);
            stopButton.SetActive(true);
        }
        isActivated = !isActivated;
    }
}



