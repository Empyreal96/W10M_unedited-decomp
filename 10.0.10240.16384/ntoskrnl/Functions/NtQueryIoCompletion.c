// NtQueryIoCompletion 
 
int __fastcall NtQueryIoCompletion(int a1, int a2, unsigned int a3, int a4, unsigned int a5)
{
  int v7; // r4
  int v8; // r9
  _DWORD *v9; // r5
  _DWORD *v10; // r0
  int v11; // r8
  int v13; // [sp+10h] [bp-20h] BYREF
  int v14; // [sp+14h] [bp-1Ch]
  int varg_r0; // [sp+38h] [bp+8h]
  int varg_r1; // [sp+3Ch] [bp+Ch]
  unsigned int varg_r2; // [sp+40h] [bp+10h]
  int varg_r3; // [sp+44h] [bp+14h]

  varg_r1 = a2;
  varg_r3 = a4;
  v13 = a3;
  v14 = a4;
  varg_r2 = a3;
  varg_r0 = a1;
  if ( a2 )
    return -1073741821;
  if ( a4 != 4 )
    return -1073741820;
  v8 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v8 )
  {
    if ( (a3 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    if ( a3 >= MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    *(_BYTE *)a3 = *(_BYTE *)a3;
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
  v7 = ObReferenceObjectByHandle(a1, 1, IoCompletionObjectType, v8, (int)&v13, 0);
  v14 = v7;
  if ( v7 >= 0 )
  {
    v11 = *(_DWORD *)(v13 + 4);
    ObfDereferenceObject(v13);
    if ( v8 )
    {
      *(_DWORD *)a3 = v11;
      if ( v9 )
        *v9 = 4;
    }
    else
    {
      *(_DWORD *)a3 = v11;
      if ( v9 )
        *v9 = 4;
    }
  }
  return v7;
}
