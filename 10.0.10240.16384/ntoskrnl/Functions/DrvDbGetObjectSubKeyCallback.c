// DrvDbGetObjectSubKeyCallback 
 
int __fastcall DrvDbGetObjectSubKeyCallback(int *a1, int a2, int a3, int a4)
{
  unsigned __int16 **v5; // r6
  unsigned int v6; // r7
  int v9; // r5
  unsigned __int16 *v10; // t1
  unsigned int v11; // r6
  unsigned __int16 *v12; // r0
  unsigned __int16 *v13; // r5
  unsigned int v14; // r3
  _WORD *v15; // r0
  int v16; // r0
  int v17; // r0
  int (__fastcall *v18)(int *, unsigned __int16 *, _DWORD, _DWORD); // r6
  unsigned int v19; // r1
  unsigned int v20; // r6
  int v22; // [sp+14h] [bp-3Ch] BYREF
  int v23; // [sp+18h] [bp-38h] BYREF
  unsigned int v24; // [sp+1Ch] [bp-34h] BYREF
  _WORD *v25; // [sp+20h] [bp-30h] BYREF
  int v26; // [sp+28h] [bp-28h] BYREF

  v5 = (unsigned __int16 **)&off_40A7A0;
  v6 = 0;
  v22 = 0;
  v23 = 0;
  v26 = a2;
  v9 = 0;
  while ( 1 )
  {
    v10 = *v5++;
    if ( !wcsicmp(a3, v10) )
      return 0;
    if ( ++v9 )
    {
      v11 = 256;
      v12 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 512, 1111770192);
      v13 = v12;
      if ( !v12 )
        return 0;
      if ( *(_WORD *)(a4 + 8) )
      {
        if ( RtlStringCchCopyExW(v12, 256, a4 + 8, &v25, &v24, 2304) >= 0 )
        {
          v14 = v24;
          if ( v24 >= 2 )
          {
            v15 = v25;
            *v25 = 92;
            v12 = v15 + 1;
            *v12 = 0;
            v11 = v14 - 2;
            goto LABEL_9;
          }
        }
LABEL_24:
        ExFreePoolWithTag((unsigned int)v13);
        return 0;
      }
LABEL_9:
      if ( RtlStringCchCopyW(v12, v11, a3) < 0 )
        goto LABEL_24;
      v16 = PnpCtxRegOpenKey(a1, v26, a3, 8);
      if ( v16 < 0 || PnpCtxRegQueryInfoKey(v16, 0, (int)&v22, (int)&v23, (int)&v23) < 0 )
        goto LABEL_24;
      if ( v22 && *(_DWORD *)(a4 + 4) < *(_DWORD *)a4 )
      {
        v17 = ExAllocatePoolWithTag(1, 540, 1111770192);
        v6 = v17;
        if ( !v17 )
          goto LABEL_24;
        memmove(v17, a4, 0x21Cu);
        ++*(_DWORD *)(v6 + 4);
        RtlStringCchCopyExW((_WORD *)(v6 + 8), 256, v13, 0, 0, 2304);
        PnpCtxRegEnumKeyWithCallback(a1, 0, (int)DrvDbGetObjectSubKeyCallback, v6);
        *(_DWORD *)(a4 + 528) = *(_DWORD *)(v6 + 528);
        *(_DWORD *)(a4 + 532) = *(_DWORD *)(v6 + 532);
        *(_DWORD *)(a4 + 536) = *(_DWORD *)(v6 + 536);
      }
      if ( v23 )
      {
        v18 = *(int (__fastcall **)(int *, unsigned __int16 *, _DWORD, _DWORD))(a4 + 520);
        if ( (!v18 || v18(a1, v13, 0, *(_DWORD *)(a4 + 524))) && RtlInitUnicodeStringEx((int)&v26, v13) >= 0 )
        {
          v19 = *(_DWORD *)(a4 + 532);
          v20 = HIWORD(v26) >> 1;
          *(_DWORD *)(a4 + 536) += v20;
          if ( v19 > v20 )
          {
            RtlStringCchCopyExW(*(_WORD **)(a4 + 528), v19, v13, 0, 0, 2304);
            *(_DWORD *)(a4 + 528) += 2 * v20;
            *(_DWORD *)(a4 + 532) -= v20;
          }
        }
      }
      if ( v6 )
        ExFreePoolWithTag(v6);
      goto LABEL_24;
    }
  }
}
