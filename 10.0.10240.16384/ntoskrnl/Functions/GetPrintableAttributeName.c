// GetPrintableAttributeName 
 
int __fastcall GetPrintableAttributeName(int a1, int a2, int a3, _DWORD *a4, _DWORD *a5)
{
  int v6; // r5
  unsigned __int16 *v7; // r8
  unsigned int v8; // r9
  unsigned int v9; // r10
  unsigned int v10; // r0
  unsigned int v11; // r4
  unsigned int v12; // r3
  _BYTE *v13; // r0
  _BYTE *v14; // r6
  const __int16 *v15; // r1
  int v16; // r0
  _DWORD *v17; // r7
  unsigned __int16 *v19; // [sp+0h] [bp-30h] BYREF
  unsigned int v20; // [sp+4h] [bp-2Ch]
  _DWORD *v21; // [sp+8h] [bp-28h]
  int v22; // [sp+Ch] [bp-24h]

  v6 = 0;
  v19 = 0;
  v20 = 0;
  v7 = 0;
  v21 = a4;
  v22 = a1;
  v8 = 0;
  if ( !a1 || !a4 || !a2 )
    return 87;
  *a5 = 1;
  if ( (unsigned int)(a2 - 1) < 4 )
    return 1336;
  v9 = *(_DWORD *)(a1 + 1);
  *a5 = 5;
  if ( a2 - 5 < v9 )
    return 1336;
  if ( a3 == 248 )
  {
    v11 = v9 + 2;
    if ( v9 + 2 < v9 )
      return 534;
  }
  else
  {
    v6 = EncodeAttributeName((unsigned __int16 *)(a1 + 5), v9, (int *)&v19);
    v7 = v19;
    if ( v6 )
      goto LABEL_33;
    v10 = wcslen(v19);
    v11 = 2 * v10 + 2;
    v20 = 2 * v10;
    if ( v11 < 2 * v10 )
      goto LABEL_10;
  }
  switch ( a3 )
  {
    case 251:
      v8 = 16;
      v12 = v11 + 16;
      break;
    case 249:
      v8 = 12;
      v12 = v11 + 12;
      break;
    case 250:
      v8 = 20;
      v12 = v11 + 20;
      break;
    default:
      goto LABEL_20;
  }
  if ( v12 < v11 )
  {
LABEL_10:
    v6 = 534;
    goto LABEL_33;
  }
  v11 = v12;
LABEL_20:
  v13 = SddlpAlloc(v11);
  v14 = v13;
  *v21 = v13;
  if ( v13 )
  {
    switch ( a3 )
    {
      case 251:
        v15 = L"@DEVICE.";
        break;
      case 249:
        v15 = L"@USER.";
        break;
      case 250:
        v15 = L"@RESOURCE.";
        break;
      default:
LABEL_29:
        v16 = (int)&v14[v8];
        if ( a3 == 248 )
        {
          v17 = a5;
          memmove(v16, *a5 + v22, v9);
        }
        else
        {
          memmove(v16, (int)v7, v20);
          v17 = a5;
        }
        *(_WORD *)&v14[2 * (v11 >> 1) - 2] = 0;
        *v17 += v9;
        goto LABEL_33;
    }
    memmove((int)v13, (int)v15, v8);
    goto LABEL_29;
  }
  v6 = 8;
LABEL_33:
  if ( v7 )
    ExFreePoolWithTag((unsigned int)v7);
  return v6;
}
