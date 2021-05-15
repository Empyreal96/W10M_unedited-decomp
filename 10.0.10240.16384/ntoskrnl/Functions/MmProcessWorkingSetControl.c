// MmProcessWorkingSetControl 
 
int __fastcall MmProcessWorkingSetControl(int a1, int *a2, unsigned int a3, int a4)
{
  int v4; // r8
  int v6; // r4
  unsigned int v7; // r6
  int v8; // r5
  int v9; // r3
  int v10; // r8
  int v11; // r10
  int v12; // r0
  char v13; // r2
  int v15; // [sp+10h] [bp-50h] BYREF
  int v16; // [sp+18h] [bp-48h]
  unsigned int v17; // [sp+1Ch] [bp-44h]
  int v18; // [sp+20h] [bp-40h]
  _DWORD _28[19]; // [sp+28h] [bp-38h] BYREF
  int varg_r3; // [sp+74h] [bp+14h]

  _28[16] = a1;
  _28[17] = a2;
  _28[18] = a3;
  varg_r3 = a4;
  v4 = (char)a4;
  LOBYTE(varg_r3) = a4;
  v15 = a1;
  if ( a3 < 0xC )
    return -1073741820;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  v16 = *a2;
  v7 = a2[1];
  v17 = v7;
  v8 = a2[2];
  v18 = v8;
  if ( v16 != 3 )
    return -1073741735;
  if ( v7 >= 2 )
    return -1073741811;
  if ( !v7 && !SeSinglePrivilegeCheck(SeDebugPrivilege, dword_922784, (char)a4, (int)&SeDebugPrivilege) )
    return -1073741727;
  v6 = ObReferenceObjectByHandleWithTag(a1, 0x2000, PsProcessType, v4, 1935109453, &v15, 0);
  if ( v6 < 0 )
    return v6;
  v9 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v10 = v15;
  if ( v9 == v15 )
  {
    v11 = 0;
  }
  else
  {
    v11 = 1;
    KiStackAttachProcess(v15, 0, (int)_28);
  }
  if ( v7 )
  {
    if ( (v8 & 0xFFFFFFE0) != 0 )
      goto LABEL_16;
    if ( ((v8 & 2) == 0) != ((v8 & 1) == 0) || (v8 & 8) != 0 && (v8 & 2) == 0 || (v8 & 0x10) != 0 && (v8 & 8) == 0 )
    {
      v6 = -1073741637;
      goto LABEL_34;
    }
    if ( (v8 & 1) != 0 )
    {
      if ( (v8 & 8) != 0 )
        SmStoreCompressionStart();
      v6 = MiEmptyWorkingSetPrivatePagesByVa((unsigned int *)(v10 + 492));
      if ( (v8 & 8) != 0 )
        SmStoreCompressionStop((v8 & 0x10) != 0);
      goto LABEL_34;
    }
    v13 = 0;
    if ( (v8 & 4) != 0 )
      v13 = 2;
    v12 = MiEmptyWorkingSet((unsigned int *)(v10 + 492), 17, v13);
LABEL_33:
    v6 = v12;
    goto LABEL_34;
  }
  if ( (v8 & 0xFFFFFFFE) == 0 )
  {
    v12 = PsSwapProcessWorkingSet(v10, (v8 & 1) == 0, 1, 0);
    goto LABEL_33;
  }
LABEL_16:
  v6 = -1073741811;
LABEL_34:
  if ( v11 == 1 )
    KiUnstackDetachProcess((unsigned int)_28, 0);
  ObfDereferenceObjectWithTag(v10);
  return v6;
}
