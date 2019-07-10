using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class ManageMotion : MonoBehaviour
{

    [SerializeField]
    RuntimeAnimatorController runtimeAnimatorController;
    [SerializeField]
    Avatar avatar;

    Animator animator;

    // Start is called before the first frame update
    void Start()
    {
        this.gameObject.AddComponent<Animator>();
        animator = GetComponent<Animator>();
        animator.runtimeAnimatorController = runtimeAnimatorController;
        animator.avatar = avatar;
        animator.enabled = true;
        animator.Play("state1");
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
