// NtQuerySection 
 
int __fastcall NtQuerySection(int a1, int a2, int *a3, unsigned int a4, unsigned int a5)
{
  int v8; // r3
  _DWORD *v9; // r6
  _DWORD *v10; // r2
  unsigned int v11; // r5
  int v12; // r4
  int v13; // r1
  int v14; // r8
  int v16; // [sp+Ch] [bp-24h] BYREF
  unsigned int v17; // [sp+10h] [bp-20h]
  int varg_r0; // [sp+38h] [bp+8h]
  int varg_r1; // [sp+3Ch] [bp+Ch]
  int *varg_r2; // [sp+40h] [bp+10h]
  unsigned int varg_r3; // [sp+44h] [bp+14h]

  v17 = a4;
  varg_r3 = a4;
  varg_r2 = a3;
  varg_r1 = a2;
  v16 = a1;
  varg_r0 = a1;
  v8 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v17 = v8;
  if ( v8 )
  {
    ProbeForWrite((unsigned int)a3, a4, 4);
    v9 = (_DWORD *)a5;
    if ( a5 )
    {
      v10 = (_DWORD *)a5;
      if ( a5 >= MmUserProbeAddress )
        v10 = (_DWORD *)MmUserProbeAddress;
      *v10 = *v10;
    }
    LOBYTE(v8) = v17;
    a1 = v16;
  }
  else
  {
    v9 = (_DWORD *)a5;
  }
  if ( a2 )
  {
    if ( a2 == 1 )
    {
      v11 = 48;
    }
    else
    {
      if ( a2 != 2 )
        return -1073741821;
      v11 = 4;
    }
  }
  else
  {
    v11 = 16;
  }
  if ( a4 < v11 )
    return -1073741820;
  v12 = ObReferenceObjectByHandle(a1, 1, MmSectionObjectType, v8, (int)&v16, 0);
  if ( v12 >= 0 )
  {
    v13 = a2;
    v14 = v16;
    v12 = MmGetSectionInformation(v16, v13, a3);
    if ( v12 >= 0 && v9 )
      *v9 = v11;
    ObfDereferenceObject(v14);
  }
  return v12;
}
