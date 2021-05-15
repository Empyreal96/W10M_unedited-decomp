// MiLargestSystemVa 
 
unsigned int __fastcall MiLargestSystemVa(int a1, int a2, int a3, int a4)
{
  unsigned int v4; // r4
  char *v5; // r6
  unsigned int v6; // r5
  int v7; // r2
  _DWORD v10[6]; // [sp+0h] [bp-18h] BYREF

  v10[1] = a3;
  v10[2] = a4;
  v4 = 0;
  v5 = byte_63505C;
  v6 = 0;
  KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_6342BC, (unsigned int)v10);
  v7 = 512;
  do
  {
    if ( *v5++ )
    {
      if ( v4 > v6 )
        v6 = v4;
      v4 = 0;
    }
    else
    {
      ++v4;
    }
    --v7;
  }
  while ( v7 );
  KeReleaseInStackQueuedSpinLock((int)v10);
  return v6;
}
