struct Pertag {
	unsigned int curtag; /* current tag index */
	int nmasters[NUMTAGS + 1]; /* number of windows in master area */
	const Layout *ltidxs[NUMTAGS + 1][2]; /* matrix of tags and layouts indexes  */
	float mfacts[NUMTAGS + 1]; /* mfacts per tag */
	unsigned int sellts[NUMTAGS + 1]; /* selected layouts */
	int showbars[NUMTAGS + 1]; /* display bar for the current tag */
	int enablegaps[NUMTAGS + 1];
	int gaps[NUMTAGS + 1];
};

void
pertagview(const Arg *arg)
{
	int i;

	if (arg->ui == ~0)
		selmon->pertag->curtag = 0;
	else {
		for (i = 0; !(selmon->tagset[selmon->seltags] & 1 << i); i++);
		selmon->pertag->curtag = i + 1;
	}

	selmon->nmaster = selmon->pertag->nmasters[selmon->pertag->curtag];
	selmon->mfact = selmon->pertag->mfacts[selmon->pertag->curtag];
	selmon->sellt = selmon->pertag->sellts[selmon->pertag->curtag];
	selmon->lt[selmon->sellt] = selmon->pertag->ltidxs[selmon->pertag->curtag][selmon->sellt];
	selmon->lt[selmon->sellt^1] = selmon->pertag->ltidxs[selmon->pertag->curtag][selmon->sellt^1];

	selmon->gappoh = (selmon->pertag->gaps[selmon->pertag->curtag] & 0xff) >> 0;
	selmon->gappov = (selmon->pertag->gaps[selmon->pertag->curtag] & 0xff00) >> 8;
	selmon->gappih = (selmon->pertag->gaps[selmon->pertag->curtag] & 0xff0000) >> 16;
	selmon->gappiv = (selmon->pertag->gaps[selmon->pertag->curtag] & 0xff000000) >> 24;

	if (selmon->showbar != selmon->pertag->showbars[selmon->pertag->curtag])
		togglebar(NULL);
}

