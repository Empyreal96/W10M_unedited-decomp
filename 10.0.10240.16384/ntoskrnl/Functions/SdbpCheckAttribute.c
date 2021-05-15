// SdbpCheckAttribute 
 
int __fastcall SdbpCheckAttribute(int *a1, int a2, _DWORD *a3, unsigned int a4, int a5)
{
  int v7; // r0
  int v8; // r2
  int v9; // r3
  int v10; // r3
  __int64 v11; // kr08_8
  bool v12; // zf

  *a1 = 0;
  v7 = 0;
  if ( a2 > 20486 )
  {
    if ( a2 != 20493 )
    {
      if ( (unsigned int)(a2 - 20498) <= 1 )
      {
        if ( a4 < 8 )
        {
          v8 = 503;
          goto LABEL_8;
        }
        v7 = SdbpCheckFromVersion(*a3, a3[1], *(_DWORD *)(a5 + 8), *(_DWORD *)(a5 + 12));
LABEL_42:
        v9 = 1;
        *a1 = v7;
        return v9;
      }
      goto LABEL_23;
    }
LABEL_39:
    if ( a4 < 8 )
    {
      v8 = 517;
      goto LABEL_8;
    }
    v7 = SdbpCheckUptoVersion(*a3, a3[1], *(_DWORD *)(a5 + 8), *(_DWORD *)(a5 + 12));
    goto LABEL_42;
  }
  switch ( a2 )
  {
    case 20486:
      goto LABEL_39;
    case 16414:
      if ( a4 < 4 )
      {
        v8 = 543;
        goto LABEL_8;
      }
      if ( *a3 < *(_DWORD *)(a5 + 8) )
        goto LABEL_17;
      goto LABEL_13;
    case 16435:
      if ( a4 < 4 )
      {
        v8 = 530;
        goto LABEL_8;
      }
      if ( *a3 > *(_DWORD *)(a5 + 8) )
        goto LABEL_17;
      goto LABEL_13;
  }
  if ( (unsigned int)(a2 - 20482) > 1 )
  {
LABEL_23:
    v10 = a2 & 0xF000;
    if ( v10 == 0x4000 )
    {
      if ( a4 < 4 )
      {
        v8 = 559;
        goto LABEL_8;
      }
      v12 = *a3 == *(_DWORD *)(a5 + 8);
    }
    else
    {
      if ( v10 != 20480 )
      {
        if ( v10 == 24576 )
        {
          if ( a4 < 2 )
          {
            v8 = 575;
            goto LABEL_8;
          }
          v7 = AslStringPatternMatchW(a3, *(_WORD **)(a5 + 8));
        }
        goto LABEL_42;
      }
      if ( a4 < 8 )
      {
        v8 = 589;
        goto LABEL_8;
      }
      v11 = *(_QWORD *)(a5 + 8);
      if ( *a3 != (_DWORD)v11 )
      {
LABEL_17:
        v7 = 0;
        goto LABEL_42;
      }
      v12 = a3[1] == HIDWORD(v11);
    }
    if ( !v12 )
      goto LABEL_17;
LABEL_13:
    v7 = 1;
    goto LABEL_42;
  }
  if ( a4 >= 8 )
  {
    v7 = SdbpCheckVersion(*a3, a3[1], *(_DWORD *)(a5 + 8), *(_DWORD *)(a5 + 12));
    goto LABEL_42;
  }
  v8 = 489;
LABEL_8:
  AslLogCallPrintf(1, (int)"SdbpCheckAttribute", v8, "Attribute size doesn't match");
  return 0;
}
