// BiConvertRegistryDataToElement 
 
int __fastcall BiConvertRegistryDataToElement(int a1, int a2, unsigned int a3, unsigned int a4, char a5, _DWORD *a6, unsigned int *a7)
{
  int v8; // r2
  unsigned int *v9; // r7
  int v10; // r8
  int v12; // r4
  unsigned int v13; // r6
  int v14; // r4
  _BYTE *v16; // r9
  unsigned int v17; // r10
  unsigned int v18; // r0
  int v19; // r0
  int v20; // r0
  int v21; // r5
  int v22; // r2
  int v23[2]; // [sp+8h] [bp-30h] BYREF
  int v24[10]; // [sp+10h] [bp-28h] BYREF

  v8 = HIBYTE(a4) & 0xF;
  v9 = a7;
  v10 = a2;
  v23[0] = 0;
  switch ( v8 )
  {
    case 2:
      if ( a3 && (a3 & 1) == 0 )
      {
        v12 = 0;
        v13 = a3;
        if ( *(_WORD *)(a2 + a3 - 2) )
        {
          v13 = a3 + 2;
          v12 = 1;
        }
        v9 = a7;
        if ( v13 <= *a7 )
        {
          memmove((int)a6, a2, a3);
          if ( v12 )
            *(_WORD *)((char *)a6 + a3) = 0;
          v14 = 0;
          goto LABEL_8;
        }
LABEL_7:
        v14 = -1073741789;
LABEL_8:
        *v9 = v13;
        return v14;
      }
      return -1073741788;
    case 1:
      if ( a3 >= 0x1C && *(_DWORD *)(a2 + 24) + 16 == a3 )
      {
        v19 = a2 + 16;
        if ( (a5 & 1) != 0 )
        {
          v20 = BiConvertBootEnvironmentDeviceToQualifiedPartition(v19, v24, v23);
        }
        else if ( (a5 & 2) != 0 )
        {
          v20 = BiConvertBootEnvironmentDeviceToUnknown(v19, v24, v23);
        }
        else
        {
          v20 = BiConvertBootEnvironmentDeviceToNt(v19, a4);
        }
        if ( v20 < 0 )
LABEL_42:
          JUMPOUT(0x813D2C);
        v21 = v24[0];
        if ( *(_DWORD *)v24[0] == 8 && BiResolveLocateDevice(a1, v24[0]) >= 0 )
        {
          v22 = *(_DWORD *)(v21 + 24);
          v13 = v23[0] - v22;
          memmove(v21, v22 + v21, v23[0] - v22);
        }
        else
        {
          v13 = v23[0];
        }
        if ( v13 > *a7 )
        {
          v14 = -1073741789;
          ExFreePoolWithTag(v21);
        }
        else
        {
          memmove((int)a6, v21, v13);
          a6[1] = *(_DWORD *)v10;
          a6[2] = *(_DWORD *)(v10 + 4);
          a6[3] = *(_DWORD *)(v10 + 8);
          a6[4] = *(_DWORD *)(v10 + 12);
          ExFreePoolWithTag(v21);
          v14 = 0;
        }
        goto LABEL_8;
      }
      return -1073741788;
    case 4:
      v16 = a6;
      v14 = 0;
      v13 = 0;
      v17 = 0;
      if ( *(_WORD *)a2 )
      {
        do
        {
          if ( v17 >= a3 )
            break;
          v13 += 16;
          if ( v13 <= *a7 )
          {
            RtlInitUnicodeString((unsigned int)v24, (unsigned __int16 *)v10);
            v14 = RtlGUIDFromString((unsigned __int16 *)v24, v16);
            if ( v14 < 0 )
              goto LABEL_42;
            v16 += 16;
          }
          v18 = wcslen((unsigned __int16 *)v10);
          v17 += 2 * v18 + 2;
          v10 += 2 * v18 + 2;
        }
        while ( *(_WORD *)v10 );
      }
      if ( v13 <= *a7 )
        goto LABEL_8;
      goto LABEL_7;
  }
  return sub_813C74();
}
