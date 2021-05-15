// AslpFileMakeBinVersionAttributes 
 
int __fastcall AslpFileMakeBinVersionAttributes(int result, int a2)
{
  int v2; // r3
  int v3; // r3
  int v4; // r3
  int v5; // r3
  __int64 v6; // r2
  __int64 v7; // r2

  if ( a2 )
  {
    *(_DWORD *)(result + 312) = 2;
    *(_DWORD *)(result + 316) = 4;
    *(_QWORD *)(result + 320) = *(unsigned int *)(a2 + 44);
    v3 = *(_DWORD *)(result + 328);
    *(_DWORD *)(result + 336) = 2;
    *(_DWORD *)(result + 340) = 4;
    *(_DWORD *)(result + 328) = v3 | 1;
    *(_QWORD *)(result + 344) = *(unsigned int *)(a2 + 48);
    v4 = *(_DWORD *)(result + 352);
    *(_DWORD *)(result + 360) = 2;
    *(_DWORD *)(result + 364) = 4;
    *(_DWORD *)(result + 352) = v4 | 1;
    *(_QWORD *)(result + 368) = *(unsigned int *)(a2 + 32);
    v5 = *(_DWORD *)(result + 376);
    *(_DWORD *)(result + 384) = 2;
    *(_DWORD *)(result + 388) = 4;
    *(_DWORD *)(result + 376) = v5 | 1;
    *(_QWORD *)(result + 392) = *(unsigned int *)(a2 + 36);
    *(_DWORD *)(result + 400) |= 1u;
    v6 = *(_QWORD *)(a2 + 16);
    *(_DWORD *)(result + 96) = 3;
    *(_DWORD *)(result + 100) = 8;
    *(_DWORD *)(result + 104) = HIDWORD(v6);
    *(_DWORD *)(result + 108) = v6;
    *(_DWORD *)(result + 112) |= 1u;
    v7 = *(_QWORD *)(a2 + 8);
    *(_DWORD *)(result + 72) = 3;
    *(_DWORD *)(result + 76) = 8;
    *(_DWORD *)(result + 80) = HIDWORD(v7);
    *(_DWORD *)(result + 84) = v7;
    v2 = *(_DWORD *)(result + 88) | 1;
  }
  else
  {
    *(_DWORD *)(result + 328) |= 2u;
    *(_DWORD *)(result + 352) |= 2u;
    *(_DWORD *)(result + 376) |= 2u;
    *(_DWORD *)(result + 400) |= 2u;
    *(_DWORD *)(result + 112) |= 2u;
    v2 = *(_DWORD *)(result + 88) | 2;
  }
  *(_DWORD *)(result + 88) = v2;
  return result;
}
