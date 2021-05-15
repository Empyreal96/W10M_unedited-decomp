// PiFindDevInstMatch 
 
int __fastcall PiFindDevInstMatch(int a1, unsigned __int16 *a2, unsigned int *a3, int a4, unsigned int *a5)
{
  unsigned int v7; // r8
  int result; // r0
  unsigned int v9; // r0
  _DWORD *v10; // r4
  int v11; // r6
  unsigned int i; // r5
  int v13; // r3
  __int16 v14; // r3
  int v15; // r0
  int v16; // r3
  int v17[3]; // [sp+10h] [bp-48h] BYREF
  unsigned __int16 v18; // [sp+1Ch] [bp-3Ch]
  unsigned __int16 *v19; // [sp+20h] [bp-38h]
  int v20; // [sp+28h] [bp-30h]
  int v21; // [sp+2Ch] [bp-2Ch]
  unsigned __int16 v22[2]; // [sp+30h] [bp-28h] BYREF
  int v23; // [sp+34h] [bp-24h]

  *(_WORD *)a4 = 0;
  *(_DWORD *)(a4 + 4) = 0;
  *a3 = 0;
  v17[0] = 0;
  v17[1] = a1;
  v7 = 0;
  v19 = a2;
  *a5 = -1;
  result = IopGetRegistryValue(a1, L"Count", 0, v17);
  if ( result < 0 )
  {
    if ( result != -1073741772 )
      return result;
  }
  else
  {
    v9 = v17[0];
    if ( *(_DWORD *)(v17[0] + 4) == 4 && *(_DWORD *)(v17[0] + 12) >= 4u )
    {
      v7 = *(_DWORD *)(*(_DWORD *)(v17[0] + 8) + v17[0]);
      *a3 = v7;
    }
    ExFreePoolWithTag(v9);
    v10 = (_DWORD *)ExAllocatePoolWithTag(1, 256, 538996816);
    if ( !v10 )
      JUMPOUT(0x7C9D20);
    v11 = ExAllocatePoolWithTag(1, 20, 538996816);
    if ( !v11 )
      return sub_7C9D18();
    for ( i = 0; i < v7; ++i )
    {
      v17[0] = v11;
      RtlStringCchPrintfExW(v11, 10, v17, 0, 0, L"%u");
      HIWORD(v20) = 20;
      v13 = (v17[0] - v11) >> 1;
      if ( v13 == -1 )
        v14 = 20;
      else
        v14 = 2 * v13;
      LOWORD(v20) = v14;
      v21 = v11;
      v15 = ZwQueryValueKey();
      if ( v15 < 0 )
      {
        if ( v15 == -2147483643 || v15 == -1073741789 )
        {
          ExFreePoolWithTag((unsigned int)v10);
          v10 = (_DWORD *)ExAllocatePoolWithTag(1, v17[2], 538996816);
          if ( !v10 )
            JUMPOUT(0x7C9D1A);
          --i;
        }
      }
      else if ( v10[1] == 1 && v10[3] > 2u )
      {
        PnpRegSzToString((char *)v10 + v10[2]);
        v22[0] = v18;
        v22[1] = v10[3];
        v23 = (int)v10 + v10[2];
        if ( RtlEqualUnicodeString(v22, v19, 1) )
        {
          v16 = v20;
          *a5 = i;
          *(_DWORD *)a4 = v16;
          *(_DWORD *)(a4 + 4) = v21;
          break;
        }
      }
    }
    ExFreePoolWithTag((unsigned int)v10);
    if ( !*(_WORD *)a4 )
      ExFreePoolWithTag(v11);
  }
  return 0;
}
