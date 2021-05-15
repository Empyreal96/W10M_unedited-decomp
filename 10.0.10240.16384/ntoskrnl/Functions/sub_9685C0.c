// sub_9685C0 
 
void __fastcall sub_9685C0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, unsigned int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, unsigned int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26, int a27, unsigned int a28, unsigned __int16 a29)
{
  int v29; // r4
  int v30; // r0
  int *v31; // r4
  int v32; // r1
  int v33; // r2
  int v34; // t1
  _DWORD *v35; // r0
  int i; // r3
  int j; // r7
  int v38; // r0
  int v39; // r0
  unsigned int v40; // r6
  unsigned int v41; // r1
  unsigned int v42; // r2
  unsigned int *v43; // r1

  if ( v29 >= 0 )
  {
    v30 = ZwQueryKey();
    if ( v30 == -2147483643 || v30 >= 0 )
    {
      if ( !a18 )
LABEL_36:
        JUMPOUT(0x94FC5E);
      v31 = &dword_416F80;
      v32 = 0;
      while ( 1 )
      {
        v34 = *v31++;
        v33 = v34;
        if ( a18 < 3 * v34 )
          break;
        if ( (unsigned int)++v32 >= 3 )
        {
          v33 = PnpDeviceOverrideHashListSize;
          goto LABEL_10;
        }
      }
      PnpDeviceOverrideHashListSize = v33;
LABEL_10:
      if ( !v33 )
      {
        v33 = 257;
        PnpDeviceOverrideHashListSize = 257;
      }
      v35 = (_DWORD *)ExAllocatePoolWithTag(1, 8 * v33, 1852403792);
      PnpDeviceOverrideHashList = (int)v35;
      if ( v35 )
      {
        for ( i = PnpDeviceOverrideHashListSize; i; --i )
        {
          *v35 = v35;
          v35[1] = v35;
          v35 += 2;
        }
        for ( j = 0; ; ++j )
        {
          v38 = ZwEnumerateKey();
          if ( v38 >= 0 )
          {
            if ( a28 <= 0x200 )
            {
              *(&a29 + (a28 >> 1)) = 0;
              v39 = ExAllocatePoolWithTag(1, 16, 1852403792);
              v40 = v39;
              if ( !v39 )
                goto LABEL_35;
              if ( !RtlCreateUnicodeString(v39 + 8, &a29) )
              {
                ExFreePoolWithTag(v40);
                goto LABEL_35;
              }
              if ( RtlHashUnicodeString((unsigned __int16 *)(v40 + 8), 1, 0, &a8) >= 0 )
              {
                v41 = a8;
              }
              else
              {
                v41 = 0;
                a8 = 0;
              }
              if ( !PnpDeviceOverrideHashListSize )
                __brkdiv0();
              v42 = PnpDeviceOverrideHashList + 8 * (v41 % PnpDeviceOverrideHashListSize);
              v43 = *(unsigned int **)(v42 + 4);
              *(_DWORD *)v40 = v42;
              *(_DWORD *)(v40 + 4) = v43;
              if ( *v43 != v42 )
                __fastfail(3u);
              *v43 = v40;
              *(_DWORD *)(v42 + 4) = v40;
            }
          }
          else
          {
            if ( v38 == -2147483622 )
              goto LABEL_36;
            if ( v38 != -2147483643 )
              goto LABEL_35;
          }
        }
      }
      PnpDeviceOverrideHashListSize = 0;
    }
  }
LABEL_35:
  JUMPOUT(0x94FC60);
}
