// CmCheckRegistry 
 
int __fastcall CmCheckRegistry(_DWORD *a1, int a2)
{
  _BYTE *v4; // r0
  unsigned int v5; // r6
  _DWORD *v6; // r8
  int v7; // r7
  int v8; // r4
  int v9; // r1
  int v10; // r3
  int v11; // r4
  int v12; // r0
  int v14; // r3
  char v15[4]; // [sp+10h] [bp-70h] BYREF
  int v16; // [sp+14h] [bp-6Ch]
  _DWORD v17[2]; // [sp+18h] [bp-68h] BYREF
  _DWORD v18[2]; // [sp+20h] [bp-60h] BYREF
  int v19; // [sp+28h] [bp-58h] BYREF
  int v20[13]; // [sp+2Ch] [bp-54h] BYREF

  v19 = 0;
  v4 = memset(v20, 0, sizeof(v20));
  v15[0] = 0;
  v5 = 0;
  v6 = 0;
  if ( a1 == CmpMasterHive )
    return 0;
  v7 = a1[7];
  v8 = a1[238] >> 3;
  v9 = a1[238] >> 6;
  v10 = a2 & 0x10000;
  v16 = a2 & 0x10000;
  v17[0] = v8;
  if ( (a2 & 0x10000) == 0 )
    goto LABEL_6;
  if ( v9 )
  {
    v4 = (_BYTE *)ExAllocatePoolWithTag(1, v9, 1649167683);
    v5 = (unsigned int)v4;
    if ( v4 )
    {
      v10 = v16;
      v18[0] = v8;
      v18[1] = v4;
      v6 = v18;
      while ( 1 )
      {
        do
        {
LABEL_6:
          if ( v10 )
          {
            RtlClearAllBits((int)v6);
            v11 = HvCheckHive(a1, v17, v6, &v19);
            if ( v11 )
            {
              v14 = 16;
              goto LABEL_25;
            }
            if ( v20[7] + v20[3] + v19 > (unsigned int)CmpReorganizeLimit )
              a1[807] |= 0x400u;
            a1[960] = v20[11];
            a1[961] = v20[12];
          }
          if ( *(int *)(a1[8] + 36) < 0 )
          {
            v11 = 3040;
            v14 = 32;
            goto LABEL_25;
          }
          v12 = CmpValidateHiveSecurityDescriptors(a1, a2, v15, v6);
          v10 = v16;
        }
        while ( v12 == 2 );
        if ( v12 )
          break;
        v11 = CmpCheckRegistry2(a1, a2, *(_DWORD *)(a1[8] + 36));
        if ( v11 != -1 )
        {
          a1[963] = v17[1];
          goto LABEL_16;
        }
        SetFailureLocation(v7, 1, 11, -1, 64);
        v10 = v16;
      }
      v11 = 3041;
      v14 = 48;
LABEL_25:
      SetFailureLocation(v7, 0, 11, v11, v14);
LABEL_16:
      if ( v5 )
        ExFreePoolWithTag(v5);
      return v11;
    }
  }
  return sub_7D2B58((int)v4);
}
