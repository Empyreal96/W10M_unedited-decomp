// RtlFormatCurrentUserKeyPath 
 
int __fastcall RtlFormatCurrentUserKeyPath(unsigned __int16 *a1)
{
  int v2; // r5
  unsigned __int16 v3; // r5
  int v4; // r0
  int v5; // r0
  int v6; // r2
  int v7; // r3
  int v8; // r2
  int v9; // r3
  unsigned __int16 v11[2]; // [sp+8h] [bp-70h] BYREF
  int v12; // [sp+Ch] [bp-6Ch]
  int v13; // [sp+10h] [bp-68h] BYREF
  _BYTE *v14; // [sp+18h] [bp-60h]

  v2 = ZwQueryInformationToken();
  if ( v2 >= 0 )
  {
    v2 = RtlLengthSidAsUnicodeString(v14, &v13);
    if ( v2 >= 0 )
    {
      v3 = v13;
      *a1 = 0;
      v4 = (unsigned __int16)(v3 + 34);
      a1[1] = v4;
      v5 = ExpAllocateStringRoutine(v4);
      *((_DWORD *)a1 + 1) = v5;
      if ( v5 )
      {
        RtlAppendUnicodeToString(a1, (int)L"\\REGISTRY\\USER\\", v6, v7);
        v11[0] = 0;
        v8 = *a1 >> 1;
        v9 = *((_DWORD *)a1 + 1);
        v11[1] = v3;
        v12 = v9 + 2 * v8;
        v2 = RtlConvertSidToUnicodeString(v11, v14, 0);
        if ( v2 < 0 )
          return sub_7EA18C();
        *a1 += v11[0];
      }
      else
      {
        v2 = -1073741801;
      }
    }
  }
  return v2;
}
