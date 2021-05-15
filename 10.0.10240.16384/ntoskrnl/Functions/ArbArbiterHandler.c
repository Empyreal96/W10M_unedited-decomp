// ArbArbiterHandler 
 
int __fastcall ArbArbiterHandler(int a1, int a2, int a3)
{
  unsigned int v6; // r4
  int v7; // r0
  int v8; // r4
  int v9; // r0
  unsigned int v10; // r1
  int v11; // r3
  int result; // r0
  int v13; // r0
  int v14; // r0

  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
  KeWaitForSingleObject(*(_DWORD *)(a1 + 4), 0, 0, 0, 0);
  switch ( a2 )
  {
    case 0:
      v7 = (*(int (__fastcall **)(int, int))(a1 + 76))(a1, a3);
      goto LABEL_3;
    case 1:
      v7 = (*(int (__fastcall **)(int, int))(a1 + 80))(a1, a3);
      goto LABEL_3;
    case 2:
      v7 = (*(int (__fastcall **)(int))(a1 + 84))(a1);
      goto LABEL_3;
    case 3:
      v7 = (*(int (__fastcall **)(int))(a1 + 88))(a1);
      goto LABEL_3;
    case 4:
    case 5:
    case 8:
      v8 = -1073741822;
      goto LABEL_9;
    case 6:
      v7 = (*(int (__fastcall **)(int, int))(a1 + 100))(a1, a3);
      goto LABEL_3;
    case 7:
      v7 = (*(int (__fastcall **)(int, int))(a1 + 96))(a1, a3);
      goto LABEL_3;
    case 9:
      v7 = (*(int (__fastcall **)(int, int))(a1 + 92))(a1, a3);
LABEL_3:
      v8 = v7;
      break;
    default:
      v8 = -1073741811;
      break;
  }
  if ( v8 >= 0 )
  {
    if ( a2 )
    {
      if ( a2 == 2 )
      {
LABEL_15:
        v13 = *(_DWORD *)(a1 + 148);
        *(_BYTE *)(a1 + 144) = 0;
        KeSetEvent(v13, 0, 0);
        goto LABEL_9;
      }
      if ( a2 != 1 )
      {
        if ( a2 != 3 )
          goto LABEL_9;
        goto LABEL_15;
      }
    }
    v14 = *(_DWORD *)(a1 + 148);
    *(_BYTE *)(a1 + 144) = 1;
    KeResetEvent(v14);
  }
LABEL_9:
  v9 = KeSetEvent(*(_DWORD *)(a1 + 4), 0, 0);
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = (__int16)(*(_WORD *)(v10 + 0x134) + 1);
  *(_WORD *)(v10 + 308) = v11;
  if ( v11 )
    result = v8;
  else
    result = sub_80D91C(v9);
  return result;
}
