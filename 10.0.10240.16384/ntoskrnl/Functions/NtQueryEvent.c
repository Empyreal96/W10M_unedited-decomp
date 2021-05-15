// NtQueryEvent 
 
int __fastcall NtQueryEvent(int a1, int a2, int *a3, int a4, unsigned int a5)
{
  int v7; // r4
  int v8; // r8
  _DWORD *v9; // r5
  _DWORD *v10; // r2
  int v11; // r9
  int v12; // r10
  int _10[16]; // [sp+10h] [bp-28h] BYREF

  _10[13] = a2;
  _10[15] = a4;
  _10[14] = (int)a3;
  _10[12] = a1;
  if ( a2 )
    return -1073741821;
  if ( a4 != 8 )
    return -1073741820;
  v8 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v8 )
  {
    ProbeForWrite(a3, 8, 4);
    v9 = (_DWORD *)a5;
    if ( a5 )
    {
      v10 = (_DWORD *)a5;
      if ( a5 >= MmUserProbeAddress )
        v10 = (_DWORD *)MmUserProbeAddress;
      *v10 = *v10;
    }
  }
  else
  {
    v9 = (_DWORD *)a5;
  }
  v7 = ObReferenceObjectByHandle(a1, 1, ExEventObjectType, v8, _10);
  _10[1] = v7;
  if ( v7 >= 0 )
  {
    v11 = *(_DWORD *)(_10[0] + 4);
    v12 = *(_BYTE *)_10[0] & 0x7F;
    ObfDereferenceObject(_10[0]);
    if ( v8 )
    {
      *a3 = v12;
      a3[1] = v11;
      if ( v9 )
        *v9 = 8;
    }
    else
    {
      *a3 = v12;
      a3[1] = v11;
      if ( v9 )
        *v9 = 8;
    }
  }
  return v7;
}
