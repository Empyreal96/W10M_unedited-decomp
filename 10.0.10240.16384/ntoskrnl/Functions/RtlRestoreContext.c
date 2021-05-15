// RtlRestoreContext 
 
void __fastcall __noreturn RtlRestoreContext(int a1, _DWORD *a2)
{
  unsigned int v2; // r2
  int v3; // r1
  int v4; // r3
  int v5; // r2
  unsigned int v6; // r3
  unsigned int v7; // r2
  int v8; // r2
  int v9; // r3
  __int64 *v10; // r1
  _QWORD *v11; // r2
  __int64 v12; // t1
  __int64 v18; // r1
  int i; // r2
  _BYTE v20[416]; // [sp-1A0h] [bp-1B0h]
  int v21; // [sp+0h] [bp-10h] BYREF
  _DWORD *v22; // [sp+4h] [bp-Ch]

  v21 = a1;
  v22 = a2;
  if ( a2 )
  {
    v2 = *a2 ^ 0x80000000;
    if ( v2 == 41 && a2[4] )
    {
      for ( i = 0; i != 416; i += 4 )
        *(_DWORD *)&v20[i] = *(_DWORD *)(a1 + i);
      RcConsolidateFrames((int)a2);
    }
    if ( v2 == 38 )
    {
      v3 = a2[5];
      *(_QWORD *)(a1 + 20) = *(_QWORD *)(v3 + 4);
      *(_QWORD *)(a1 + 28) = *(_QWORD *)(v3 + 12);
      *(_QWORD *)(a1 + 36) = *(_QWORD *)(v3 + 20);
      *(_QWORD *)(a1 + 44) = *(_QWORD *)(v3 + 28);
      v4 = *(_DWORD *)(v3 + 40);
      *(_DWORD *)(a1 + 56) = *(_DWORD *)(v3 + 36);
      *(_DWORD *)(a1 + 64) = v4;
      v5 = *(_DWORD *)(v3 + 44);
      v6 = __get_CPSR();
      *(_DWORD *)(a1 + 72) = v5;
      *(_DWORD *)(a1 + 68) = v6 | 0x20;
      *(_QWORD *)(a1 + 144) = *(_QWORD *)(v3 + 48);
      *(_QWORD *)(a1 + 152) = *(_QWORD *)(v3 + 56);
      *(_QWORD *)(a1 + 160) = *(_QWORD *)(v3 + 64);
      *(_QWORD *)(a1 + 168) = *(_QWORD *)(v3 + 72);
      *(_QWORD *)(a1 + 176) = *(_QWORD *)(v3 + 80);
      *(_QWORD *)(a1 + 184) = *(_QWORD *)(v3 + 88);
      *(_QWORD *)(a1 + 192) = *(_QWORD *)(v3 + 96);
      *(_QWORD *)(a1 + 200) = *(_QWORD *)(v3 + 104);
    }
  }
  if ( (__mrc(15, 0, 1, 0, 2) & 0xF00000) != 0 )
  {
    _R1 = *(_DWORD *)(a1 + 72) & 0xFFC8FFFF;
    __asm { VMSR            FPSCR, R1 }
  }
  else
  {
    v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    if ( v7 )
    {
      v8 = *(_DWORD *)(v7 + 320);
      if ( v8 )
      {
        *(_DWORD *)(v8 + 4) = *(_DWORD *)(a1 + 72);
        v9 = 32;
        v10 = (__int64 *)(a1 + 80);
        v11 = (_QWORD *)(v8 + 16);
        do
        {
          --v9;
          v12 = *v10++;
          *v11++ = v12;
        }
        while ( v9 );
      }
    }
  }
  __disable_irq();
  __asm { CPS.W           #0x12 }
  v18 = *(_QWORD *)(a1 + 64);
  v21 = v18 & 0xFFFFFFFE;
  v22 = (_DWORD *)(HIDWORD(v18) & 0xFFFFFEA0 | 0x33 | ((unsigned __int16)__get_CPSR() | 0x20) & 0x140);
  __asm { RFEFD.W         SP }
}
