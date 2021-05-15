// WheaInitializeProcessor 
 
int __fastcall WheaInitializeProcessor(int a1, int a2)
{
  int result; // r0
  _DWORD *v5; // r0
  int *i; // r4
  int (__fastcall *v7)(int, char *, int); // r3

  result = 0;
  if ( a2 )
  {
    for ( i = (int *)dword_641934; i != &dword_641934; i = (int *)*i )
    {
      v7 = (int (__fastcall *)(int, char *, int))dword_649F60[7 * i[8]];
      __dmb(0xBu);
      result = v7(a2, (char *)i + 73, i[10]);
      if ( result < 0 )
        break;
      *(int *)((char *)i + 85) = 2;
    }
  }
  else
  {
    v5 = (_DWORD *)ExAllocatePoolWithTag(512, 12, 1634035799);
    if ( v5 )
    {
      v5[1] = &WheapErrorSourceTable;
      *v5 = dword_641930;
      v5[2] = WheapWorkQueue;
      *(_DWORD *)(a1 + 3592) = v5;
      result = 0;
    }
    else
    {
      result = -1073741670;
      ++WheapStatus;
      dword_619894 |= 0x10u;
    }
  }
  return result;
}
