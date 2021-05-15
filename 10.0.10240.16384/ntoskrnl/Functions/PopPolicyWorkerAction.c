// PopPolicyWorkerAction 
 
int PopPolicyWorkerAction()
{
  int v0; // r7
  int v1; // r5
  int v2; // r8
  int v3; // r6
  int v4; // r0
  int *i; // r4
  int v6; // r0
  int v8[2]; // [sp+8h] [bp-30h] BYREF
  int v9[10]; // [sp+10h] [bp-28h] BYREF

  v0 = 0;
  PopAcquirePolicyLock();
  if ( byte_61EC61 == 1 )
  {
    v1 = dword_61EC64;
    byte_61EC61 = 2;
    v2 = dword_61EC74;
    v3 = PopIssueActionRequest(0, dword_61EC64, dword_61EC68, dword_61EC6C);
    v0 = 1;
    if ( v3 < 0 && (PoDebug & 0xA) != 0 )
      DbgPrint("PopPolicyWorkerAction: action request %d failed %08lx\n", v1, v3);
    if ( (PopAction[0] & 2) != 0 )
    {
      if ( dword_61EC68 == 5 )
        dword_61EC74 = 6;
      else
        dword_61EC74 = v2;
      dword_61EC6C = dword_61EC6C & 0xFFFFFFFC | 0x80000000;
      PopAction[0] &= 0xFDu;
      byte_61EC61 = 1;
      v4 = 2;
    }
    else
    {
      if ( (dword_682610 & 0x8000) != 0 )
      {
        v8[1] = v3;
        v9[0] = (int)v8;
        v9[1] = 0;
        v9[2] = 8;
        v9[3] = 0;
        v8[0] = v1;
        EtwTraceKernelEvent(v9, 1, 0x80008000, 4643, 4200450);
      }
      dword_61EC70 = v3;
      byte_61EC61 = 0;
      for ( i = (int *)PopActionWaiters; i != &PopActionWaiters; i = (int *)*i )
        PopCompleteAction(i[2], v3);
      v4 = 1;
    }
    PopGetPolicyWorker(v4);
  }
  v6 = PopReleasePolicyLock();
  if ( v0 && PoPdcCallbacks )
    PoPdcCallbacks(v6);
  if ( *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x134) )
    __fastfail(0x20u);
  return 0;
}
