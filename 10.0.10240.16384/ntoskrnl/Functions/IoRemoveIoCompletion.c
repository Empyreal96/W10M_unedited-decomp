// IoRemoveIoCompletion 
 
int __fastcall IoRemoveIoCompletion(int a1, int a2, int **a3, unsigned int a4, unsigned int *a5, char a6, _DWORD *a7, unsigned __int8 a8)
{
  int **v8; // r4
  unsigned int v9; // r6
  int v10; // r2
  unsigned int i; // r5
  int v12; // r4
  int v13; // r8
  int v14; // r9
  int v15; // r10
  int v16; // r3
  unsigned int *v17; // r8
  unsigned int v18; // r2
  _DWORD *v19; // r3
  int v21; // [sp+8h] [bp-58h]
  int v22; // [sp+Ch] [bp-54h]
  int v23; // [sp+10h] [bp-50h]
  int v24; // [sp+18h] [bp-48h]
  int **v25; // [sp+24h] [bp-3Ch]
  int v26; // [sp+28h] [bp-38h]
  int v27; // [sp+2Ch] [bp-34h]

  v8 = a3;
  v25 = a3;
  v23 = a2;
  v24 = a1;
  v9 = KeRemoveQueueEx(a1, a6, a8, a7, a3, a4);
  v10 = 0;
  for ( i = 0; i < v9; ++i )
  {
    v12 = (int)v8[i];
    if ( v12 == 128 || v12 == 257 || v12 == 258 || v12 == 192 )
    {
      v10 = v12;
      break;
    }
    if ( *(_BYTE *)(v12 + 8) )
    {
      if ( *(_BYTE *)(v12 + 8) == 2 )
      {
        v22 = *(_DWORD *)(v12 + 28);
        v21 = *(_DWORD *)(v12 + 24);
        v14 = *(_DWORD *)(v12 + 36);
        v15 = *(_DWORD *)(v12 + 32);
        v27 = *(_DWORD *)(v12 + 40);
        v17 = (unsigned int *)(v12 + 48);
        v26 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          KiAcquireSpinLockInstrumented(v12 + 48);
        }
        else
        {
          do
            v18 = __ldrex(v17);
          while ( __strex(1u, v17) );
          __dmb(0xBu);
          if ( v18 )
            KxWaitForSpinLockAndAcquire(v12 + 48);
        }
        __dmb(0xBu);
        *(_BYTE *)(v12 + 52) = 0;
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(v12 + 48);
        }
        else
        {
          __dmb(0xBu);
          *v17 = 0;
        }
        KfLowerIrql(v26);
        ObfDereferenceObjectWithTag(v27);
        ObfDereferenceObjectWithTag(v24);
        ObfDereferenceObjectWithTag(v12);
      }
      else
      {
        v22 = *(_DWORD *)(v12 + 16);
        v21 = *(_DWORD *)(v12 + 12);
        v14 = *(_DWORD *)(v12 + 20);
        v15 = *(_DWORD *)(v12 + 24);
        IopFreeMiniCompletionPacket(v12, 257);
      }
      v13 = v22;
    }
    else
    {
      v13 = *(_DWORD *)(v12 - 36);
      v21 = *(_DWORD *)(v12 - 24);
      v14 = *(_DWORD *)(v12 - 64);
      v15 = *(_DWORD *)(v12 - 60);
      v16 = *(_DWORD *)(v12 - 80);
      if ( (v16 & 0x2000) != 0 )
      {
        IopPostProcessIrp(v12 - 88);
      }
      else if ( (v16 & 0x8000) == 0 || !sub_456A04((unsigned int *)(v12 - 40), -1) )
      {
        pIoFreeIrp(v12 - 88);
      }
    }
    v19 = (_DWORD *)(v23 + 16 * i);
    *v19 = v21;
    v19[1] = v13;
    v19[2] = v14;
    v19[3] = v15;
    v10 = 0;
    v8 = v25;
  }
  *a5 = v9;
  return v10;
}
