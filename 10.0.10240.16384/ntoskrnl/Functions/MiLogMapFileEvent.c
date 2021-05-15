// MiLogMapFileEvent 
 
int *__fastcall MiLogMapFileEvent(int *result, int a2, int a3)
{
  int v4; // r3
  _DWORD v5[10]; // [sp+8h] [bp-28h] BYREF

  v4 = result[7] & 7;
  if ( v4 != 1 )
  {
    MiFillMapFileInfo((int)result, v5, a3, v4);
    result = MiLogPerfMemoryEvent(a2, 0x8000u, (int)v5, 28, 4200707);
  }
  return result;
}
