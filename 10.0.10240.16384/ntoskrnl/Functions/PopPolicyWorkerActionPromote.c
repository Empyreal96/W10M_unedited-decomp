// PopPolicyWorkerActionPromote 
 
int PopPolicyWorkerActionPromote()
{
  char v0; // r5
  int v1; // r0

  PopAcquirePolicyLock();
  v0 = PopAction[0];
  if ( !PopAction[0] )
    goto LABEL_14;
  if ( !byte_61EC61 )
  {
    if ( (PopAction[0] & 2) == 0 )
      goto LABEL_14;
    byte_61EC61 = 1;
    v1 = 2;
    goto LABEL_13;
  }
  if ( byte_61EC61 != 2 )
  {
    if ( byte_61EC61 != 3 && (PoDebug & 1) != 0 )
      DbgPrint("PopAction: invalid state %d\n", (unsigned __int8)byte_61EC61);
    goto LABEL_14;
  }
  if ( PopIssueActionRequest(1, dword_61EC64, dword_61EC68, dword_61EC6C) >= 0 )
  {
    PopAction[0] &= ~v0;
    goto LABEL_14;
  }
  if ( byte_61EC61 != 2 )
  {
    v1 = 1;
LABEL_13:
    PopGetPolicyWorker(v1);
  }
LABEL_14:
  PopReleasePolicyLock();
  if ( *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x134) )
    __fastfail(0x20u);
  return 0;
}
