// PspCreateUserProcessEcp 
 
int __fastcall PspCreateUserProcessEcp(_DWORD *a1, int a2)
{
  _WORD *v2; // r8
  int v5; // r5
  int v6; // r4
  int v8; // [sp+8h] [bp-38h] BYREF
  _WORD *v9; // [sp+Ch] [bp-34h] BYREF
  _DWORD v10[12]; // [sp+10h] [bp-30h] BYREF

  v2 = 0;
  v9 = 0;
  v10[0] = -521917953;
  v10[1] = 1315270108;
  v10[2] = -800737622;
  v10[3] = 143262554;
  *a1 = 0;
  a1[1] = 0;
  a1[2] = 0;
  a1[3] = 0;
  v8 = 0;
  *(_WORD *)a1 = 16;
  v5 = FsRtlAllocateExtraCreateParameterList(0, &v8);
  if ( v5 < 0 )
  {
    v6 = v8;
  }
  else
  {
    v5 = FsRtlAllocateExtraCreateParameter(v10, 8u, 0, 0, 1883468624, &v9);
    v6 = v8;
    v2 = v9;
    if ( v5 >= 0 )
    {
      *v9 = 8;
      v2[1] = 0;
      *((_DWORD *)v2 + 1) = a2;
      v5 = FsRtlInsertExtraCreateParameter(v6, v2);
      if ( v5 >= 0 )
      {
        a1[1] = v6;
        v6 = 0;
        v2 = 0;
      }
    }
  }
  if ( v6 )
    return sub_7F476C();
  if ( v2 )
    FsRtlFreeExtraCreateParameter(v2);
  return v5;
}
