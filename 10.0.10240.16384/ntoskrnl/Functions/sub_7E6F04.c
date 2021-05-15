// sub_7E6F04 
 
int __fastcall sub_7E6F04(int a1, int a2, int a3, int a4, int a5, int a6, char a7)
{
  int v8; // r5
  int v9; // r6
  int v10; // r7
  char v11; // r10
  unsigned int v12; // r5
  unsigned int *v13; // r4
  unsigned int v14; // r5
  unsigned int v15; // r1
  int v16; // r3
  int (__fastcall *v17)(int); // [sp-4h] [bp-4h]

  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v12 + 308);
  __dmb(0xBu);
  v13 = (unsigned int *)(v9 + 68);
  do
    v14 = __ldrex(v13);
  while ( __strex(1u, v13) );
  __dmb(0xBu);
  if ( !v14 )
  {
    ObfReferenceObject(v9);
    goto LABEL_11;
  }
  v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v16 = (__int16)(*(_WORD *)(v15 + 0x134) + 1);
  *(_WORD *)(v15 + 308) = v16;
  if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
    KiCheckForKernelApcDelivery(a1);
  v8 = IopAcquireFileObjectLock(v9, v11, (*(_DWORD *)(v9 + 44) & v10) != 0, &a7);
  if ( !a7 )
  {
LABEL_11:
    KeResetEvent(v9 + 92);
    JUMPOUT(0x6F3BA6);
  }
  ObfDereferenceObject(v9);
  return v17(v8);
}
