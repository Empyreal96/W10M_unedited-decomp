// sub_81A780 
 
// local variable allocation has failed, the output may be wrong!
void sub_81A780()
{
  _DWORD *v0; // r5
  int v1; // r6
  int v2; // r7
  _DWORD *v3; // r8
  int v4; // r10
  int v5; // r0
  int v6; // r1 OVERLAPPED
  _DWORD *v7; // r2 OVERLAPPED

  if ( v3[7] != v4 )
  {
    if ( !IopCheckIfMergeRequired(v3[8], v1) )
      goto LABEL_14;
    if ( v1 != v2 )
    {
LABEL_6:
      IopMergeRelationLists(v1, v3[8], 1);
      IopFreeRelationList((_DWORD *)v3[8]);
      if ( v0 == v3 )
      {
        v0[8] = 0;
      }
      else
      {
        *(_QWORD *)&v6 = *(_QWORD *)v3;
        if ( *(_DWORD **)(*v3 + 4) != v3 || (_DWORD *)*v7 != v3 )
          __fastfail(3u);
        *v7 = v6;
        *(_DWORD *)(v6 + 4) = v7;
        ExFreePoolWithTag((unsigned int)v3);
      }
LABEL_14:
      JUMPOUT(0x7B7C58);
    }
    v0 = v3;
    v5 = IopAllocateRelationList(3);
    v1 = v5;
    if ( v5 )
    {
      IopMergeRelationLists(v5, v2, 0);
      goto LABEL_6;
    }
  }
  JUMPOUT(0x7B7C5E);
}
