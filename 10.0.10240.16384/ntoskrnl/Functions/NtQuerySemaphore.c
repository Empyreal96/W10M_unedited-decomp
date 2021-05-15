// NtQuerySemaphore 
 
int __fastcall NtQuerySemaphore(int a1, int a2, unsigned int a3, int a4, unsigned int a5)
{
  _DWORD *v7; // r5
  _DWORD *v8; // r1
  int v9; // r4
  int v10; // r8
  int v11; // r9
  char v13; // [sp+8h] [bp-30h]
  int _10[16]; // [sp+10h] [bp-28h] BYREF

  _10[15] = a4;
  _10[14] = a3;
  _10[13] = a2;
  _10[12] = a1;
  v13 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v13 )
  {
    if ( (a3 & 3) != 0 )
      ExRaiseDatatypeMisalignment();
    if ( a3 >= MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    *(_BYTE *)a3 = *(_BYTE *)a3;
    *(_BYTE *)(a3 + 4) = *(_BYTE *)(a3 + 4);
    v7 = (_DWORD *)a5;
    if ( a5 )
    {
      v8 = (_DWORD *)a5;
      if ( a5 >= MmUserProbeAddress )
        v8 = (_DWORD *)MmUserProbeAddress;
      *v8 = *v8;
    }
  }
  else
  {
    v7 = (_DWORD *)a5;
  }
  if ( a2 )
    return -1073741821;
  if ( a4 != 8 )
    return -1073741820;
  v9 = ObReferenceObjectByHandle(a1, 1, ExSemaphoreObjectType, v13, (int)_10, 0);
  _10[1] = v9;
  if ( v9 >= 0 )
  {
    v10 = *(_DWORD *)(_10[0] + 4);
    v11 = *(_DWORD *)(_10[0] + 16);
    ObfDereferenceObject(_10[0]);
    if ( v13 )
    {
      *(_DWORD *)a3 = v10;
      *(_DWORD *)(a3 + 4) = v11;
      if ( v7 )
        *v7 = 8;
    }
    else
    {
      *(_DWORD *)a3 = v10;
      *(_DWORD *)(a3 + 4) = v11;
      if ( v7 )
        *v7 = 8;
    }
  }
  return v9;
}
