// CmpAddProcessorCapabilities 
 
int CmpAddProcessorCapabilities()
{
  int v0; // r5
  unsigned __int8 *v1; // r1
  int v2; // r0
  int result; // r0
  unsigned int v4; // r2
  int v5; // r1
  char v13[8]; // [sp+10h] [bp-30h] BYREF
  unsigned __int16 v14[20]; // [sp+18h] [bp-28h] BYREF

  v0 = 0;
  while ( 2 )
  {
    v1 = (unsigned __int8 *)CmpCpuidRegisters + 5 * v0;
    v2 = RtlStringCbPrintfW(
           v14,
           0x10u,
           (int)L"CP%5X",
           v1[4] | (16 * (v1[3] | (16 * (v1[2] | (16 * (v1[1] | (16 * *v1))))))));
    switch ( v0 )
    {
      case 0:
        __mrc(15, 0, 0, 1, 0);
        goto LABEL_4;
      case 1:
        __mrc(15, 0, 0, 1, 1);
        goto LABEL_4;
      case 2:
        __mrc(15, 0, 0, 1, 2);
        goto LABEL_4;
      case 3:
        __mrc(15, 0, 0, 1, 4);
        goto LABEL_4;
      case 4:
        __mrc(15, 0, 0, 1, 5);
        goto LABEL_4;
      case 5:
        __mrc(15, 0, 0, 1, 6);
        goto LABEL_4;
      case 6:
        __mrc(15, 0, 0, 1, 7);
        goto LABEL_4;
      case 7:
        __mrc(15, 0, 0, 2, 0);
        goto LABEL_4;
      case 8:
        __mrc(15, 0, 0, 2, 1);
        goto LABEL_4;
      case 9:
        __mrc(15, 0, 0, 2, 2);
        goto LABEL_4;
      case 10:
        __mrc(15, 0, 0, 2, 3);
        goto LABEL_4;
      case 11:
        __mrc(15, 0, 0, 2, 4);
        goto LABEL_4;
      case 12:
        __mrc(15, 0, 0, 2, 5);
        goto LABEL_4;
      case 13:
        __mrc(15, 0, 0, 2, 6);
        goto LABEL_4;
      case 14:
        __mrc(15, 0, 0, 2, 7);
        goto LABEL_4;
      case 15:
        __mrc(15, 0, 0, 0, 0);
        goto LABEL_4;
      case 16:
        __mrc(15, 0, 0, 0, 1);
        goto LABEL_4;
      case 17:
        __mrc(15, 0, 1, 0, 0);
        goto LABEL_4;
      case 18:
        __mrc(15, 0, 1, 0, 1);
        goto LABEL_4;
      case 19:
        __mrc(15, 0, 2, 0, 0);
        goto LABEL_4;
      case 20:
        __mrc(15, 0, 10, 2, 0);
        goto LABEL_4;
      case 21:
        __mrc(15, 0, 10, 2, 1);
        goto LABEL_4;
      case 22:
        v4 = __mrc(15, 0, 1, 0, 2);
        v5 = v4 & 0xF00000;
        if ( (v4 & 0xF00000) != 0 )
        {
          __asm { VMRS            R3, FPSID }
LABEL_9:
          if ( !v5 )
          {
            __mcr(15, 0, v4, 1, 0, 2);
            __isb(0xFu);
          }
LABEL_4:
          RtlInitUnicodeString((unsigned int)v13, v14);
          result = ZwSetValueKey();
          if ( (unsigned int)++v0 >= 0x1B )
            return result;
          continue;
        }
        return sub_54D944(v2);
      case 23:
        v4 = __mrc(15, 0, 1, 0, 2);
        v5 = v4 & 0xF00000;
        if ( (v4 & 0xF00000) == 0 )
        {
          __mcr(15, 0, v4 | 0xF00000, 1, 0, 2);
          __isb(0xFu);
        }
        __asm { VMRS            R3, MVFR0 }
        goto LABEL_9;
      case 24:
        v4 = __mrc(15, 0, 1, 0, 2);
        v5 = v4 & 0xF00000;
        if ( (v4 & 0xF00000) == 0 )
        {
          __mcr(15, 0, v4 | 0xF00000, 1, 0, 2);
          __isb(0xFu);
        }
        __asm { VMRS            R3, MVFR1 }
        goto LABEL_9;
      case 25:
        __mrc(14, 0, 0, 0, 0);
        goto LABEL_4;
      case 26:
        __mrc(15, 0, 0, 1, 3);
        goto LABEL_4;
      default:
        goto LABEL_4;
    }
  }
}
