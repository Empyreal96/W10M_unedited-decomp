// KiDeliverApc 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KiDeliverApc(int result, int a2, int a3)
{
  unsigned int v4; // r4
  int v5; // r3
  int v6; // r7
  int v7; // r8
  _DWORD *v8; // r6
  unsigned int *v9; // lr
  unsigned int v10; // r2
  int v11; // r5
  int (__fastcall *v12)(int, void (__fastcall **)(int, int, int), int *, int *, int *); // r10
  unsigned int *v13; // r0
  unsigned int v14; // r2
  __int64 *v15; // r5
  void (__fastcall *v16)(int, void (__fastcall **)(int, int, int), int *, int *, int *); // r10
  __int64 v17; // kr00_8
  int v18; // r1 OVERLAPPED
  _DWORD *v19; // r2 OVERLAPPED
  int v20; // r1 OVERLAPPED
  _DWORD *v21; // r2 OVERLAPPED
  int v22; // r2
  int v23; // r3
  void (__fastcall *v24)(int, int, int); // [sp+8h] [bp-38h] BYREF
  int v25; // [sp+Ch] [bp-34h] BYREF
  int v26; // [sp+10h] [bp-30h] BYREF
  int v27; // [sp+14h] [bp-2Ch] BYREF
  int v28; // [sp+18h] [bp-28h]
  int v29; // [sp+1Ch] [bp-24h]

  result = (char)result;
  v28 = (char)result;
  v29 = a2;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = *(__int16 *)(v4 + 0x136);
  v6 = *(_DWORD *)(v4 + 96);
  v7 = *(_DWORD *)(v4 + 116);
  *(_DWORD *)(v4 + 96) = a3;
  *(_BYTE *)(v4 + 121) = 0;
  if ( !v5 )
  {
    __dmb(0xFu);
    v8 = (_DWORD *)(v4 + 100);
    while ( 1 )
    {
      if ( (_DWORD *)*v8 == v8 )
        goto LABEL_15;
      KfRaiseIrql(2);
      v9 = (unsigned int *)(v4 + 44);
      while ( 1 )
      {
        do
          v10 = __ldrex(v9);
        while ( __strex(1u, v9) );
        __dmb(0xBu);
        if ( !v10 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v9 );
      }
      v11 = *(_DWORD *)(v4 + 100);
      if ( (_DWORD *)v11 == v8 )
        break;
      *(_BYTE *)(v4 + 121) = 0;
      __pld((void *)(v11 - 12));
      v12 = *(int (__fastcall **)(int, void (__fastcall **)(int, int, int), int *, int *, int *))(v11 + 8);
      v24 = *(void (__fastcall **)(int, int, int))(v11 + 16);
      v27 = *(_DWORD *)(v11 + 20);
      v26 = *(_DWORD *)(v11 + 24);
      v25 = *(_DWORD *)(v11 + 28);
      if ( v24 )
      {
        if ( *(_BYTE *)(v4 + 120) || *(_WORD *)(v4 + 308) )
        {
          __dmb(0xBu);
          *(_DWORD *)(v4 + 44) = 0;
LABEL_12:
          result = KfLowerIrql(1);
          goto LABEL_13;
        }
        *(_QWORD *)&v20 = *(_QWORD *)v11;
        if ( *(_DWORD *)(*(_DWORD *)v11 + 4) != v11 || *v21 != v11 )
          __fastfail(3u);
        *v21 = v20;
        *(_DWORD *)(v20 + 4) = v21;
        *(_BYTE *)(v11 + 34) = 0;
        __dmb(0xBu);
        *v9 = 0;
        KfLowerIrql(1);
        *(_BYTE *)(v4 + 120) = 1;
        result = v12(v11 - 12, &v24, &v27, &v26, &v25);
        if ( v24 )
        {
          KfLowerIrql(0);
          v24(v27, v26, v25);
          result = KfRaiseIrql(1);
        }
        *(_BYTE *)(v4 + 120) = 0;
      }
      else
      {
        *(_QWORD *)&v18 = *(_QWORD *)v11;
        if ( *(_DWORD *)(*(_DWORD *)v11 + 4) != v11 || *v19 != v11 )
          sub_50C3FC();
        *v19 = v18;
        *(_DWORD *)(v18 + 4) = v19;
        *(_BYTE *)(v11 + 34) = 0;
        __dmb(0xBu);
        *v9 = 0;
        KfLowerIrql(1);
        *(_BYTE *)(v4 + 120) |= 2u;
        result = v12(v11 - 12, &v24, &v27, &v26, &v25);
        *(_BYTE *)(v4 + 120) &= 0xFDu;
      }
    }
    __dmb(0xBu);
    *(_DWORD *)(v4 + 44) = 0;
    result = KfLowerIrql(1);
LABEL_15:
    if ( v28 == 1 && *(_DWORD *)(v4 + 108) != v4 + 108 && *(_BYTE *)(v4 + 122) )
    {
      KfRaiseIrql(2);
      v13 = (unsigned int *)(v4 + 44);
      while ( 1 )
      {
        do
          v14 = __ldrex(v13);
        while ( __strex(1u, v13) );
        __dmb(0xBu);
        if ( !v14 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v13 );
      }
      *(_BYTE *)(v4 + 122) = 0;
      v15 = *(__int64 **)(v4 + 108);
      if ( v15 == (__int64 *)(v4 + 108) )
      {
        __dmb(0xBu);
        *v13 = 0;
        goto LABEL_12;
      }
      v16 = (void (__fastcall *)(int, void (__fastcall **)(int, int, int), int *, int *, int *))*((_DWORD *)v15 + 2);
      v24 = (void (__fastcall *)(int, int, int))*((_DWORD *)v15 + 4);
      v27 = *((_DWORD *)v15 + 5);
      v26 = *((_DWORD *)v15 + 6);
      v25 = *((_DWORD *)v15 + 7);
      v17 = *v15;
      if ( *(__int64 **)(*(_DWORD *)v15 + 4) != v15 || *(__int64 **)HIDWORD(v17) != v15 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v17) = v17;
      *(_DWORD *)(v17 + 4) = HIDWORD(v17);
      *((_BYTE *)v15 + 34) = 0;
      __dmb(0xBu);
      *v13 = 0;
      KfLowerIrql(1);
      v16((int)v15 - 12, &v24, &v27, &v26, &v25);
      if ( v24 )
        result = KiInitializeUserApc(v29, a3, (int)v24, v27, v26, v25);
      else
        result = KeTestAlertThread(1);
    }
  }
LABEL_13:
  if ( *(_DWORD *)(v4 + 116) != v7 )
  {
    if ( (__get_CPSR() & 0x80) != 0 )
    {
      v22 = 0;
    }
    else
    {
      __disable_irq();
      v22 = 1;
    }
    v23 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
    if ( v22 )
      __enable_irq();
    KeBugCheck2(5, v7, *(_DWORD *)(v4 + 116), *(unsigned __int8 *)(v4 + 362), v23 & 0x10001, 0);
  }
  *(_DWORD *)(v4 + 96) = v6;
  return result;
}
