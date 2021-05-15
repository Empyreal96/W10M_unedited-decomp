// ExWaitForRundownProtectionReleaseCacheAware 
 
unsigned int __fastcall ExWaitForRundownProtectionReleaseCacheAware(_DWORD *a1)
{
  unsigned int result; // r0
  unsigned int v3; // r4
  unsigned int v4; // r6
  unsigned int *v5; // r2
  unsigned int v6; // r1
  unsigned int v7; // r4
  unsigned int v8; // [sp+8h] [bp-28h] BYREF
  char v9[4]; // [sp+Ch] [bp-24h] BYREF
  int v10; // [sp+10h] [bp-20h]
  int v11[7]; // [sp+14h] [bp-1Ch] BYREF

  result = a1[3];
  v3 = 0;
  v4 = 0;
  v8 = 0;
  if ( result )
  {
    do
    {
      if ( !result )
        __brkdiv0();
      v5 = (unsigned int *)(*a1 + v4 % result * a1[2]);
      __dmb(0xBu);
      do
        v6 = __ldrex(v5);
      while ( __strex((unsigned int)&v8 + 1, v5) );
      __dmb(0xBu);
      result = a1[3];
      ++v4;
      v3 += v6;
    }
    while ( v4 < result );
    if ( v3 )
    {
      v9[0] = 1;
      v9[1] = 0;
      v9[2] = 4;
      v10 = 0;
      v11[1] = (int)v11;
      v11[0] = (int)v11;
      v7 = v3 >> 1;
      __dmb(0xBu);
      do
        result = __ldrex(&v8);
      while ( __strex(result + v7, &v8) );
      __dmb(0xBu);
      if ( result != -v7 )
        result = KeWaitForSingleObject((unsigned int)v9, 0, 0, 0, 0);
    }
  }
  return result;
}
