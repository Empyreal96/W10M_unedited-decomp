// CmpCopySaclToVirtualKey 
 
int __fastcall CmpCopySaclToVirtualKey(int a1, int a2, int a3, int a4, unsigned int a5)
{
  int v6; // r1
  int (__fastcall *v7)(int, int, _DWORD *); // r4
  int v9; // r9
  int v11; // r0
  int v12; // r4
  int v13; // r7
  int v14; // r0
  int v15; // r5
  int v16; // r2
  int v17; // r3
  bool v19; // [sp+8h] [bp-48h] BYREF
  char v20[3]; // [sp+9h] [bp-47h] BYREF
  int v21; // [sp+Ch] [bp-44h] BYREF
  _WORD *v22; // [sp+10h] [bp-40h] BYREF
  int v23; // [sp+14h] [bp-3Ch] BYREF
  _DWORD v24[2]; // [sp+18h] [bp-38h] BYREF
  char v25[2]; // [sp+20h] [bp-30h] BYREF
  __int16 v26; // [sp+22h] [bp-2Eh]

  v6 = *(_DWORD *)(a2 + 44);
  v7 = *(int (__fastcall **)(int, int, _DWORD *))(a1 + 4);
  v23 = -1;
  v24[0] = -1;
  v9 = *(_DWORD *)(a4 + 44);
  v21 = 0;
  v11 = v7(a1, v6, v24);
  if ( !v11 )
    return -1073741670;
  v12 = RtlGetSaclSecurityDescriptor(v11 + 20, v20, &v21, &v19);
  if ( v12 >= 0 )
  {
    v13 = (unsigned __int8)v20[0];
    if ( v20[0] )
    {
      v14 = (*(int (__fastcall **)(int, int, int *))(a3 + 4))(a3, v9, &v23);
      v15 = v14;
      if ( v14 )
      {
        v12 = RtlCreateSecurityDescriptor(v25, *(unsigned __int8 *)(v14 + 20));
        if ( v12 >= 0 )
        {
          v26 = *(_WORD *)(v15 + 22) & 0x7FFF;
          v12 = RtlSetSaclSecurityDescriptor((int)v25, v13, v21, v19);
          if ( v12 >= 0 )
          {
            v12 = RtlGetOwnerSecurityDescriptor(v15 + 20, &v22, &v19);
            if ( v12 >= 0 )
            {
              v12 = RtlSetOwnerSecurityDescriptor((int)v25, (int)v22, v19);
              if ( v12 >= 0 )
              {
                v12 = RtlGetGroupSecurityDescriptor(v15 + 20, &v22, &v19);
                if ( v12 >= 0 )
                {
                  v12 = RtlSetGroupSecurityDescriptor((int)v25, (int)v22, v19);
                  if ( v12 >= 0 )
                  {
                    v12 = RtlGetDaclSecurityDescriptor(v15 + 20, v20, &v21, &v19);
                    if ( v12 >= 0 )
                    {
                      v12 = RtlSetDaclSecurityDescriptor((int)v25, (unsigned __int8)v20[0], v21, v19);
                      if ( v12 >= 0 )
                      {
                        v12 = SeCaptureSecurityDescriptor((unsigned int)v25, 0, 1, 1, (unsigned int *)&v22);
                        if ( v12 >= 0 )
                        {
                          if ( HvpMarkCellDirty(a3, v9, 0, 0)
                            && HvpMarkCellDirty(a3, *(_DWORD *)(v15 + 4), 0, 0)
                            && HvpMarkCellDirty(a3, *(_DWORD *)(v15 + 8), 0, 0) )
                          {
                            CmpFreeSecurityDescriptor(a3, a5, v16, v17);
                            v12 = CmpAssignSecurityDescriptor(a3, a5, a4, v22, 0);
                            SeReleaseSecurityDescriptor((unsigned int)v22, 0, 1);
                          }
                          else
                          {
                            SeReleaseSecurityDescriptor((unsigned int)v22, 0, 1);
                            v12 = -1073741443;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        (*(void (__fastcall **)(int, int *))(a3 + 8))(a3, &v23);
      }
    }
  }
  (*(void (__fastcall **)(int, _DWORD *))(a1 + 8))(a1, v24);
  return v12;
}
