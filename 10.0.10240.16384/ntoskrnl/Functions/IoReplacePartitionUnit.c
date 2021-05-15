// IoReplacePartitionUnit 
 
int __fastcall IoReplacePartitionUnit(int a1, int a2, int a3)
{
  int v6; // r2
  _DWORD v8[16]; // [sp+8h] [bp-40h] BYREF

  memset(v8, 0, 48);
  v8[2] = a3;
  v8[3] = -1073741823;
  v8[0] = a1;
  v8[1] = a2;
  KeInitializeEvent((int)&v8[4], 0, 0);
  v6 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  if ( v6 == PsInitialSystemProcess )
  {
    PnpReplacePartitionUnit(v8);
  }
  else
  {
    v8[10] = PnpReplacePartitionUnit;
    v8[11] = v8;
    v8[8] = 0;
    ExQueueWorkItem(&v8[8], 1);
    KeWaitForSingleObject((unsigned int)&v8[4], 0, 0, 0, 0);
  }
  return v8[3];
}
