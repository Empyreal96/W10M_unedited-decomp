// sub_7C04D8 
 
void sub_7C04D8()
{
  unsigned int v0; // r5
  char *v1; // r8
  int v2; // r7
  int i; // r4
  char v4; // r3
  char v5; // t1
  int v6; // r6
  __int64 v7; // r2
  unsigned int *v8; // r1
  unsigned int *v9; // r2
  unsigned int v10; // r0
  unsigned int v11; // r2

  v1 = PspResourceFlags;
  v2 = 0;
  for ( i = v0; ; i += 256 )
  {
    v5 = *v1;
    v1 += 8;
    v4 = v5;
    if ( (v5 & 2) == 0 && (v4 & 1) != 0 )
    {
      v6 = *(_DWORD *)(i + 136) != 0;
      v7 = *(_QWORD *)(i + 128);
      if ( HIDWORD(v7) + (_DWORD)v7 )
      {
        if ( *(_DWORD *)(i + 136) )
        {
          __dmb(0xBu);
          v8 = (unsigned int *)(i + 128);
          v9 = (unsigned int *)(i + 132);
          do
            v10 = __ldrex(v9);
          while ( __strex(0, v9) );
          __dmb(0xBu);
          do
            v11 = __ldrex(v8);
          while ( __strex(0, v8) );
          __dmb(0xBu);
          LODWORD(v7) = v11 + v10;
        }
      }
      else
      {
        LODWORD(v7) = 0;
      }
      if ( (_DWORD)v7 || v6 )
        PspReturnResourceQuota(v2, i, v7, v6);
    }
    if ( ++v2 >= 4 )
    {
      PspRemoveQuotaBlock(v0);
      ExFreePoolWithTag(v0);
      JUMPOUT(0x6A72A2);
    }
  }
}
