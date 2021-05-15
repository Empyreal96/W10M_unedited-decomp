// IopLiveDumpCorralDpc 
 
int __fastcall IopLiveDumpCorralDpc(int a1, int a2, int a3, int a4)
{
  unsigned int v5; // r4
  int v6; // r1
  int v7; // r2
  int v8; // r3
  int v10; // [sp+0h] [bp-18h] BYREF
  int v11; // [sp+4h] [bp-14h]
  int v12; // [sp+8h] [bp-10h]
  int v13; // [sp+Ch] [bp-Ch]

  v10 = a1;
  v13 = a4;
  v11 = 0;
  v12 = 0;
  v10 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594);
  v11 = 0;
  v5 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  RtlCaptureContext(*(_DWORD **)(v5 + 2712), a2, 0, v10);
  KiSaveProcessorControlState((_DWORD *)(v5 + 1440), v6, v7, v8);
  do
    IopLiveDumpProcessCorralStateChange(a2, &v10);
  while ( v11 != -1 );
  return v10;
}
