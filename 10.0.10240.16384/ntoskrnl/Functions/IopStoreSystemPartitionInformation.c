// IopStoreSystemPartitionInformation 
 
int __fastcall IopStoreSystemPartitionInformation(int a1, unsigned __int16 *a2)
{
  int v3; // r0
  int result; // r0
  int v5; // r3
  int v6; // r4
  int v7; // r4
  unsigned int v8; // r1
  int v9; // r2
  int v10; // r3
  __int16 v11[2]; // [sp+8h] [bp-278h] BYREF
  _WORD *v12; // [sp+Ch] [bp-274h]
  __int16 v13; // [sp+10h] [bp-270h] BYREF
  __int16 v14; // [sp+12h] [bp-26Eh]
  __int16 *v15; // [sp+14h] [bp-26Ch]
  int v16; // [sp+18h] [bp-268h] BYREF
  int v17; // [sp+1Ch] [bp-264h]
  int v18; // [sp+20h] [bp-260h] BYREF
  int v19; // [sp+28h] [bp-258h]
  int v20; // [sp+2Ch] [bp-254h]
  __int16 *v21; // [sp+30h] [bp-250h]
  int v22; // [sp+34h] [bp-24Ch]
  int v23; // [sp+38h] [bp-248h]
  int v24; // [sp+3Ch] [bp-244h]
  __int16 v25; // [sp+40h] [bp-240h] BYREF
  __int16 v26; // [sp+42h] [bp-23Eh]
  __int16 v27; // [sp+44h] [bp-23Ch]
  __int16 v28; // [sp+46h] [bp-23Ah]
  __int16 v29; // [sp+48h] [bp-238h]
  __int16 v30; // [sp+4Ah] [bp-236h]
  __int16 v31; // [sp+4Ch] [bp-234h]
  __int16 v32; // [sp+4Eh] [bp-232h]
  __int16 v33; // [sp+50h] [bp-230h]
  __int16 v34; // [sp+52h] [bp-22Eh]
  __int16 v35; // [sp+54h] [bp-22Ch]
  __int16 v36; // [sp+56h] [bp-22Ah]
  __int16 v37; // [sp+58h] [bp-228h]
  __int16 v38; // [sp+5Ah] [bp-226h]
  __int16 v39; // [sp+5Ch] [bp-224h]
  __int16 v40; // [sp+5Eh] [bp-222h]
  _WORD v41[272]; // [sp+60h] [bp-220h] BYREF

  v3 = RtlStringCchCopyW(v41, 0x100u, dword_9209D4);
  v12 = v41;
  v11[0] = IoArcHalDeviceName;
  if ( (unsigned __int16)IoArcHalDeviceName > 0x200u )
    return sub_9691B4(v3);
  v11[1] = 510;
  v19 = 24;
  v20 = 0;
  v21 = v11;
  v23 = 0;
  v24 = 0;
  v22 = 576;
  result = ZwOpenSymbolicLinkObject();
  if ( result < 0 )
  {
LABEL_6:
    if ( result == -1073741788 )
    {
      result = IopOpenRegistryKeyEx(&v18);
      if ( result >= 0 )
      {
        v25 = 83;
        v26 = 101;
        v27 = 116;
        v28 = 117;
        v29 = 112;
        v30 = 0;
        v14 = 12;
        v13 = 10;
        v15 = &v25;
        v7 = IopCreateRegistryKeyEx(&v16, v18, (int)&v13, 983103, 0, 0);
        result = ObCloseHandle(v18);
        if ( v7 >= 0 )
        {
          if ( !InitIsWinPEMode )
          {
            v25 = 83;
            v26 = 121;
            v27 = 115;
            v28 = 116;
            v29 = 101;
            v30 = 109;
            v31 = 80;
            v32 = 97;
            v33 = 114;
            v34 = 116;
            v35 = 105;
            v36 = 116;
            v37 = 105;
            v38 = 111;
            v39 = 110;
            v40 = 0;
            v14 = 32;
            v13 = 30;
            NtSetValueKey(v16, (int)&v13, 0, 1, (int)v12, (unsigned __int16)v11[0] + 2);
          }
          v25 = 79;
          v26 = 115;
          v27 = 76;
          v28 = 111;
          v29 = 97;
          v30 = 100;
          v31 = 101;
          v32 = 114;
          v33 = 80;
          v34 = 97;
          v35 = 116;
          v36 = 104;
          v37 = 0;
          v8 = *a2;
          v14 = 26;
          v13 = 24;
          if ( v8 > 2 )
          {
            v9 = *((_DWORD *)a2 + 1);
            if ( *(_WORD *)(v8 + v9 - 2) == 92 )
            {
              v10 = (unsigned __int16)(v8 - 2);
              *a2 = v10;
              *(_WORD *)(v10 + v9) = 0;
            }
          }
          NtSetValueKey(v16, (int)&v13, 0, 1, *((_DWORD *)a2 + 1), *a2 + 2);
          result = ObCloseHandle(v16);
        }
      }
    }
  }
  else
  {
    while ( 1 )
    {
      v6 = NtQuerySymbolicLinkObject(v17, (unsigned int)v11, 0, v5);
      result = ObCloseHandle(v17);
      if ( v6 < 0 )
        break;
      v12[(unsigned __int16)v11[0] >> 1] = 0;
      v19 = 24;
      v20 = 0;
      v23 = 0;
      v24 = 0;
      v21 = v11;
      v22 = 576;
      result = ZwOpenSymbolicLinkObject();
      if ( result < 0 )
        goto LABEL_6;
    }
  }
  return result;
}
