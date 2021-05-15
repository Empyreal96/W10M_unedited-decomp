// PopBcdEstablishResumeObject 
 
int __fastcall PopBcdEstablishResumeObject(int a1, int *a2)
{
  int v3; // r4
  int v5; // r2
  int v6; // r5
  int v7; // r6
  int v8; // r0
  int v10[2]; // [sp+8h] [bp-40h] BYREF
  int v11; // [sp+10h] [bp-38h] BYREF
  int v12; // [sp+14h] [bp-34h]
  char v13[8]; // [sp+18h] [bp-30h] BYREF
  _DWORD v14[10]; // [sp+20h] [bp-28h] BYREF

  v3 = 0;
  v11 = 0;
  v10[0] = 0;
  v6 = BcdOpenObject(a1, &GUID_CURRENT_BOOT_ENTRY, &v11);
  v7 = v11;
  if ( v6 < 0 )
    goto LABEL_19;
  v11 = 16;
  v6 = BcdGetElementDataWithFlags(v7, 0x23000003u, v5, (int)v14, &v11);
  if ( v6 >= 0 )
  {
    v6 = BcdOpenObject(a1, v14, v10);
    v3 = v10[0];
    if ( v6 >= 0 )
    {
      v6 = BcdQueryObject(v10[0], 1, &v11, 0);
      if ( v6 >= 0 )
      {
        if ( (v12 & 0xF0000000) == 0x10000000 && (v12 & 0xF00000) == 0x200000 && (v12 & 0xFFFFF) == 4 )
        {
          v11 = 2;
          v6 = BcdGetElementDataWithFlags(v3, 0x26000003u, 4, (int)v13, &v11);
          if ( v6 < 0 || !v13[0] )
            v6 = PopBcdSetDefaultResumeObjectElements(v3, v7);
          goto LABEL_19;
        }
        v6 = -1073741275;
      }
    }
    if ( v3 )
    {
      BcdCloseObject(v3);
      v3 = 0;
      v10[0] = 0;
    }
  }
  if ( !InitIsWinPEMode )
  {
    v8 = PopBcdRegenerateResumeObject(a1, v7, v10);
    v3 = v10[0];
    v6 = v8;
  }
  if ( v6 >= 0 )
    v6 = 0;
  else
    v3 = 0;
LABEL_19:
  if ( v7 )
    BcdCloseObject(v7);
  if ( v6 < 0 )
  {
    if ( !v3 )
      return v6;
LABEL_25:
    BcdCloseObject(v3);
    return v6;
  }
  if ( !a2 )
    goto LABEL_25;
  *a2 = v3;
  return v6;
}
