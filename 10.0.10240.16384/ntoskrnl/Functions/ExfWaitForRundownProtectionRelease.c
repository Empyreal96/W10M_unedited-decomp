// ExfWaitForRundownProtectionRelease 
 
unsigned int *__fastcall ExfWaitForRundownProtectionRelease(unsigned int *result, unsigned int a2)
{
  unsigned int v2; // r4
  unsigned int v3; // r5
  int v4; // r2
  unsigned int v5; // r1
  unsigned int v6; // r1
  unsigned int v7; // r2
  unsigned int v8; // [sp+8h] [bp-28h] BYREF
  char v9[4]; // [sp+Ch] [bp-24h] BYREF
  int v10; // [sp+10h] [bp-20h]
  _DWORD v11[2]; // [sp+14h] [bp-1Ch] BYREF
  int v12[5]; // [sp+1Ch] [bp-14h] BYREF

  v2 = a2 >> 1;
  v12[0] = 1;
  v8 = a2 >> 1;
  __dmb(0xBu);
  do
    v3 = __ldrex(result);
  while ( v3 == a2 && __strex((unsigned int)&v8 + 1, result) );
  __dmb(0xBu);
  if ( v3 != a2 )
  {
    do
    {
      v2 = v3 >> 1;
      v8 = v3 >> 1;
      v6 = v3;
      __dmb(0xBu);
      do
        v7 = __ldrex(result);
      while ( v7 == v3 && __strex((unsigned int)&v8 + 1, result) );
      v3 = v7;
      __dmb(0xBu);
    }
    while ( v7 != v6 );
  }
  if ( v2 )
  {
    result = (unsigned int *)KeGetCurrentIrql(result);
    if ( (unsigned int)result < 2 )
    {
      if ( MEMORY[0xFFFF936A] <= 1u )
        v4 = 0;
      else
        v4 = ExpSpinCount;
      while ( (v12[0] & 1) != 0 )
      {
        if ( !v4 )
        {
          v9[0] = 1;
          v10 = 0;
          v9[1] = 0;
          v11[0] = v11;
          v11[1] = v11;
          v9[2] = 4;
          __dmb(0xBu);
          do
            v5 = __ldrex((unsigned __int8 *)v12);
          while ( __strex(v5 & 0xFE, (unsigned __int8 *)v12) );
          __dmb(0xBu);
          if ( (v5 & 1) != 0 )
            result = (unsigned int *)KeWaitForSingleObject((unsigned int)v9, 0, 0, 0, 0);
          return result;
        }
        --v4;
        __dmb(0xAu);
        __yield();
      }
    }
    else
    {
      result = (unsigned int *)sub_50EE08();
    }
  }
  return result;
}
