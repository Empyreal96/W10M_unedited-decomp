// MiLogFailedDriverLoad 
 
unsigned int __fastcall MiLogFailedDriverLoad(int *a1, int *a2, unsigned int a3, int a4)
{
  int v4; // r5
  int v5; // r4
  int v6; // r0
  unsigned int v7; // r7
  int v8; // r4
  int v11; // r8
  int v12; // r9
  unsigned int v13; // r0
  int v14; // r3
  int v15; // r3
  unsigned int v16; // r0
  int v17; // r0
  int v18; // r6
  int v19; // r5
  int *v20; // r7
  unsigned int v21; // r4
  _WORD *v22; // r5
  __int64 v24; // [sp+0h] [bp-50h] BYREF
  unsigned __int16 v25[4]; // [sp+8h] [bp-48h] BYREF
  int v26[2]; // [sp+10h] [bp-40h] BYREF
  __int16 v27; // [sp+18h] [bp-38h]
  const __int16 *v28; // [sp+1Ch] [bp-34h]
  int v29; // [sp+20h] [bp-30h]
  int v30; // [sp+24h] [bp-2Ch]
  __int64 v31; // [sp+28h] [bp-28h]

  v4 = a4;
  v26[0] = *a1;
  v5 = a1[1];
  v6 = *(unsigned __int16 *)a1;
  v7 = 0;
  v26[1] = v5;
  v8 = v6 + 2;
  v24 = 0i64;
  v11 = 1;
  v12 = 0;
  if ( !a2 && !a3 || a4 != -1073741214 && a4 != -1073741213 && a4 != -1073741772 && a4 != -1073741702 )
    goto LABEL_14;
  v28 = L"cannot find";
  v13 = wcslen(L"cannot find");
  v14 = *(unsigned __int16 *)a2;
  v27 = 2 * v13;
  v8 += v14 + 2 * v13 + 4;
  v11 = 3;
  v29 = *a2;
  v30 = a2[1];
  if ( a3 )
  {
    if ( (a3 & 0xFFFF0000) != 0 )
    {
      RtlInitAnsiString((unsigned int)v25, a3);
      if ( RtlAnsiStringToUnicodeString((unsigned __int16 *)&v24, v25, 1, v15) < 0 )
        v12 = 1;
      v11 = 4;
      v8 += (unsigned __int16)v24 + 2;
      v31 = v24;
    }
    else
    {
      v7 = a3;
    }
    if ( v12 == 1 )
    {
LABEL_14:
      v7 = v4;
      if ( v4 == -1073741670 || v4 == -1073741663 || v4 == -1073741801 )
        v4 = -1073741670;
      else
        v4 = -1073741204;
      v28 = L"failed to load";
      v16 = wcslen(L"failed to load");
      v27 = 2 * v16;
      v8 += 2 * v16 + 2;
      ++v11;
    }
  }
  if ( (unsigned int)(v8 + 48) < 0xFF )
  {
    v17 = IoAllocateGenericErrorLogEntry((unsigned __int8)(v8 + 48));
    v18 = v17;
    if ( v17 )
    {
      *(_DWORD *)(v17 + 12) = 1073741850;
      *(_DWORD *)(v17 + 16) = v7;
      *(_DWORD *)(v17 + 20) = v4;
      v19 = v17 + 48;
      *(_WORD *)(v17 + 6) = 48;
      if ( v11 )
      {
        v20 = v26;
        do
        {
          v21 = *(unsigned __int16 *)v20;
          memmove(v19, v20[1], v21);
          v22 = (_WORD *)(v19 + 2 * (v21 >> 1));
          v20 += 2;
          *v22 = 32;
          v19 = (int)(v22 + 1);
          --v11;
        }
        while ( v11 );
      }
      *(_WORD *)(v19 - 2) = 0;
      *(_WORD *)(v18 + 4) = 1;
      IoWriteErrorLogEntry(v18);
    }
  }
  return RtlFreeAnsiString(&v24);
}
