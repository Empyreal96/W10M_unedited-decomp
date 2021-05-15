// KiSaveCurrentEtwTraceBuffer 
 
void __fastcall __spoils<R2,R3,R12> KiSaveCurrentEtwTraceBuffer(int a1, int a2, unsigned int a3, int a4)
{
  int v4; // r0
  int v5; // r1
  int v6; // r0
  int v7; // r1
  int v8[2]; // [sp+0h] [bp-18h] BYREF
  unsigned int v9; // [sp+8h] [bp-10h]
  int v10; // [sp+Ch] [bp-Ch]

  v9 = a3;
  v10 = a4;
  if ( EtwGetProcessorBuffer(2, *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594), v8) >= 0 )
  {
    v4 = v8[0];
    v5 = 0x2000;
    if ( v9 < 0x2000 )
      v5 = v9;
    KiCurrentEtwBufferBase = v8[0];
    if ( v9 >= 0x2000 )
      v4 = v9 + v8[0] - v5;
    KiCurrentEtwBufferOffset = v9 + v8[0];
    IoAddTriageDumpDataBlock(v4, v5);
    IoAddTriageDumpDataBlock((int)&KiCurrentEtwBufferBase, 4);
    IoAddTriageDumpDataBlock((int)&KiCurrentEtwBufferOffset, 4);
  }
  if ( ErrorLogSessionOpened
    && EtwGetProcessorBuffer(
         (unsigned __int16)IopErrorLogSession,
         *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594),
         v8) >= 0 )
  {
    v6 = v8[0];
    v7 = 4096;
    if ( v9 < 0x1000 )
      v7 = v9;
    KiCurrentErrLogBufferBase = v8[0];
    if ( v9 >= 0x1000 )
      v6 = v9 + v8[0] - v7;
    KiCurrentErrLogBufferOffset = v9 + v8[0];
    IoAddTriageDumpDataBlock(v6, v7);
    IoAddTriageDumpDataBlock((int)&KiCurrentErrLogBufferBase, 4);
    IoAddTriageDumpDataBlock((int)&KiCurrentErrLogBufferOffset, 4);
  }
}
