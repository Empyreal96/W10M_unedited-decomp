// DrvDbCreateDatabaseNode 
 
int __fastcall DrvDbCreateDatabaseNode(int a1, unsigned __int16 *a2, int a3, unsigned __int16 *a4, int a5, int a6, int a7, unsigned int *a8)
{
  _BYTE *v13; // r0
  unsigned int v14; // r4
  int v15; // r3
  int v16; // r5
  int v17; // r0
  unsigned int *v18; // r1
  int v19; // r1
  int v20; // r2
  _DWORD *v21; // r1
  unsigned int v22; // r6
  int v23; // [sp+18h] [bp-28h] BYREF
  int v24[9]; // [sp+1Ch] [bp-24h] BYREF

  v23 = 0;
  v24[0] = 0;
  *a8 = 0;
  v24[1] = a3;
  if ( !a4 )
    return sub_819348();
  v13 = (_BYTE *)ExAllocatePoolWithTag(1, 80, 1111770192);
  v14 = (unsigned int)v13;
  if ( v13 )
  {
    memset(v13, 0, 80);
    v15 = *(_DWORD *)(a1 + 4);
    *(_DWORD *)(v14 + 28) = a5;
    *(_DWORD *)(v14 + 32) = v15;
    *(_DWORD *)(v14 + 16) = a3;
    *(_DWORD *)(v14 + 36) = a6;
    *(_DWORD *)(v14 + 40) = a7;
    if ( RtlCreateUnicodeString(v14 + 8, a2) && RtlCreateUnicodeString(v14 + 20, a4) )
    {
      v17 = ExAllocatePoolWithTag(512, 56, 1111770192);
      *(_DWORD *)(v14 + 72) = v17;
      if ( v17 )
      {
        v16 = ExInitializeResourceLite(v17);
        if ( v16 >= 0 )
        {
          v18 = *(unsigned int **)(a1 + 16);
          *(_DWORD *)v14 = a1 + 12;
          *(_DWORD *)(v14 + 4) = v18;
          if ( *v18 != a1 + 12 )
            __fastfail(3u);
          *v18 = v14;
          *(_DWORD *)(a1 + 16) = v14;
          if ( (a5 & 0x10) == 0
            || (v19 = *(_DWORD *)(a1 + 20)) == 0
            || (v16 = DrvDbOpenObjectRegKey((int **)a1, v19, 1, (int)a2, 0x2000000, 1, (int)&v23, v24), v16 >= 0)
            && (v24[0] != 1
             || (v16 = DrvDbSetDriverDatabaseMappedProperty(
                         a1,
                         a2,
                         v23,
                         DEVPKEY_DriverDatabase_RegistryPath,
                         18,
                         *(_DWORD *)(v14 + 24),
                         *(unsigned __int16 *)(v14 + 22)),
                 v16 >= 0)) )
          {
            *a8 = v14;
            v14 = 0;
          }
        }
        else
        {
          ExFreePoolWithTag(*(_DWORD *)(v14 + 72));
          *(_DWORD *)(v14 + 72) = 0;
        }
      }
      else
      {
        v16 = -1073741670;
      }
    }
    else
    {
      v16 = -1073741670;
    }
  }
  else
  {
    v16 = -1073741801;
  }
  if ( v23 )
    ZwClose();
  if ( v14 )
  {
    v20 = *(_DWORD *)v14;
    if ( *(_DWORD *)v14 )
    {
      v21 = *(_DWORD **)(v14 + 4);
      if ( *(_DWORD *)(v20 + 4) != v14 || *v21 != v14 )
        __fastfail(3u);
      *v21 = v20;
      *(_DWORD *)(v20 + 4) = v21;
    }
    v22 = *(_DWORD *)(v14 + 72);
    if ( v22 )
    {
      ExDeleteResourceLite(*(_DWORD **)(v14 + 72));
      ExFreePoolWithTag(v22);
    }
    RtlFreeAnsiString((_DWORD *)(v14 + 8));
    RtlFreeAnsiString((_DWORD *)(v14 + 20));
    ExFreePoolWithTag(v14);
  }
  return v16;
}
