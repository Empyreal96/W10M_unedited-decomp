// SepBuildObjectSecurityDescriptor 
 
int __fastcall SepBuildObjectSecurityDescriptor(int a1, unsigned __int8 *a2, int a3, int *a4)
{
  int v8; // r1
  int v9; // r5
  unsigned __int8 *v10; // r8
  int v11; // r4
  __int16 v12; // r2
  int v13; // r3
  unsigned __int8 *v14; // r0
  int v15; // r2
  int v16; // r3
  __int16 v17; // r3
  int v18; // r1
  int v19; // r3
  unsigned __int8 *v21[2]; // [sp+0h] [bp-38h] BYREF
  _DWORD v22[12]; // [sp+8h] [bp-30h] BYREF

  LOBYTE(v22[0]) = 0;
  memset((_BYTE *)v22 + 1, 0, 19);
  v8 = *a2;
  v9 = 0;
  v10 = 0;
  v21[0] = 0;
  *a4 = 0;
  v11 = RtlCreateSecurityDescriptor(v22, v8);
  if ( v11 < 0 )
    return v11;
  v12 = *((_WORD *)a2 + 1);
  HIWORD(v22[0]) = v12 & 0x7FFF;
  if ( (v12 & 4) == 0 )
    goto LABEL_12;
  if ( (v12 & 0x8000) != 0 )
  {
    v13 = *((_DWORD *)a2 + 4);
    if ( !v13 )
      goto LABEL_12;
    v14 = &a2[v13];
  }
  else
  {
    v14 = (unsigned __int8 *)*((_DWORD *)a2 + 4);
  }
  if ( !v14 || !*((_WORD *)v14 + 2) )
  {
LABEL_12:
    if ( (*(_WORD *)(a1 + 2) & 4) == 0 )
    {
LABEL_13:
      v15 = 0;
      goto LABEL_18;
    }
    if ( (*(_WORD *)(a1 + 2) & 0x8000) != 0 )
    {
      v16 = *(_DWORD *)(a1 + 16);
      if ( !v16 )
        goto LABEL_13;
      v15 = v16 + a1;
    }
    else
    {
      v15 = *(_DWORD *)(a1 + 16);
    }
LABEL_18:
    v11 = RtlSetDaclSecurityDescriptor((int)v22, 1, v15, 0);
    if ( v11 < 0 )
      return v11;
    goto LABEL_19;
  }
  v11 = SepBuildDaclWithAllApplicationPackageSid(v14, a3, v21);
  v10 = v21[0];
  if ( v11 >= 0 )
  {
    v11 = RtlSetDaclSecurityDescriptor((int)v22, 1, (int)v21[0], 0);
    if ( v11 >= 0 )
    {
LABEL_19:
      v17 = *((_WORD *)a2 + 1);
      v18 = (v17 & 0x10) != 0;
      v19 = (v17 & 0x20) != 0;
      if ( !v18 || (v11 = RtlSetSaclSecurityDescriptor((int)v22, v18, 0, v19), v11 >= 0) )
      {
        v21[0] = 0;
        v11 = RtlMakeSelfRelativeSD(v22, 0, (unsigned int *)v21);
        if ( v11 == -1073741789 )
        {
          v9 = ExAllocatePoolWithTag(1, (int)v21[0], 1683187027);
          if ( v9 )
          {
            v11 = RtlMakeSelfRelativeSD(v22, v9, (unsigned int *)v21);
            if ( v11 >= 0 )
              *a4 = v9;
          }
          else
          {
            v11 = -1073741801;
          }
        }
      }
      goto LABEL_26;
    }
  }
LABEL_26:
  if ( v10 )
    ExFreePoolWithTag((unsigned int)v10);
  if ( v11 < 0 && v9 )
    ExFreePoolWithTag(v9);
  return v11;
}
