// ViPnpVerifyMinorWasProcessedProperly 
 
int __fastcall ViPnpVerifyMinorWasProcessedProperly(int result, int a2, int a3, int a4, int a5, int a6)
{
  int v7; // r5
  int v8; // r0
  int v9; // r0
  int v10; // r3
  unsigned int *v11; // r4
  unsigned int v12; // r6
  unsigned int *v13; // r9
  int v14; // r7
  int v15; // t1
  int v16; // r8

  v7 = result;
  switch ( *(_BYTE *)(a2 + 1) )
  {
    case 0:
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
      if ( !a6 && !a4 )
      {
        v8 = 535;
        goto LABEL_35;
      }
      return result;
    case 2:
      if ( !a6 && a4 != 2 )
      {
        v8 = 774;
        goto LABEL_35;
      }
      return result;
    case 7:
      if ( *(_DWORD *)(a2 + 8) != 4 )
        goto LABEL_18;
      if ( a3 )
      {
        if ( a4 != 2 )
          goto LABEL_18;
        v9 = 536;
        goto LABEL_17;
      }
      if ( !a4 )
      {
        v9 = 554;
LABEL_17:
        result = VfErrorReport1(v9, a5, v7);
        goto LABEL_18;
      }
      if ( *(int *)(result + 24) >= 0 && !*(_DWORD *)(result + 28) )
      {
        v9 = 555;
        goto LABEL_17;
      }
LABEL_18:
      v10 = VfIoDisabled;
      __dmb(0xBu);
      if ( !v10 && *(int *)(v7 + 24) >= 0 )
      {
        v11 = *(unsigned int **)(v7 + 28);
        if ( v11 )
        {
          if ( *(_DWORD *)(a2 + 8) <= 4u )
          {
            result = MmIsNonPagedSystemAddressValid(*(_DWORD *)(v7 + 28), a2, a3);
            if ( result )
            {
              v12 = 0;
              if ( *v11 )
              {
                v13 = v11;
                do
                {
                  v15 = v13[1];
                  ++v13;
                  v14 = v15;
                  result = IovUtilIsDeviceObjectMarked(v15, 5);
                  if ( !result )
                  {
                    v16 = IovUtilGetBottomDeviceObject(v14);
                    if ( v16 != v14 )
                      VfErrorReport10(584, a5, v7, v14);
                    IovUtilMarkDeviceObject(v14, 5);
                    result = ObfDereferenceObject(v16);
                  }
                  ++v12;
                }
                while ( v12 < *v11 );
              }
            }
          }
        }
      }
      return result;
    case 0xA:
    case 0xB:
    case 0xC:
    case 0xF:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x15:
      goto LABEL_32;
    case 0x13:
      if ( *(_DWORD *)(a2 + 8) <= 3u )
      {
LABEL_32:
        if ( a3 && a4 == 2 )
        {
          v8 = 536;
LABEL_35:
          result = VfErrorReport1(v8, a5, v7);
        }
      }
      return result;
    default:
      return result;
  }
}
