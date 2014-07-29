#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int is_leap(int64_t y) {
	return y % 4 == 0 && ((y % 100 != 0) || (y % 400 == 0));
}

int month_dates[] = {
	0,
	31, /* jan */
	28, /* feb */
	31, /* march */
	30, /* april */
	31, /* may */
	30, /* june */
	31, /* july */
	31, /* aug */
	30, /* sep */
	31, /* oct */
	30, /* nov */
	31  /* dec */
};

int leap_month_dates[] = {
	0,
	31, /* jan */
	29, /* feb */
	31, /* march */
	30, /* april */
	31, /* may */
	30, /* june */
	31, /* july */
	31, /* aug */
	30, /* sep */
	31, /* oct */
	30, /* nov */
	31  /* dec */
};

int leap_sundays[8];
int normal_sundays[8];

void calc_normal_sundays() {
	int i;

	for (i = 0; i < 7; ++i) {
		int n = 0;
		int num_ds = i;
		int m;

		for (m = 1; m <= 12; ++m) {
			n += (num_ds == 0);
			num_ds = (num_ds + month_dates[m]) % 7;
		}
		normal_sundays[i] = n;
	}
}

void calc_leap_sundays() {
	int i;

	for (i = 0; i < 7; ++i) {
		int n = 0;
		int num_ds = i;
		int m;

		for (m = 1; m <= 12; ++m) {
			n += (num_ds == 0);
			num_ds = (num_ds + leap_month_dates[m]) % 7;
		}
		leap_sundays[i] = n;
	}
}

int cycle_sun[2801];
int cycle_day[2801];

void calc_sunday_cycle()
{
	int y, dd = 1, sun = 0;
	cycle_sun[0] = sun;
	cycle_day[0] = dd;

	for (y = 0; y < 2800; ++y) {
		if (is_leap(y+1900)) {
			sun += leap_sundays[dd%7];
			dd += 366;
		} else {
			sun += normal_sundays[dd%7];
			dd += 365;
		}
		cycle_sun[y+1] = sun;
		cycle_day[y+1] = dd%7;
	}
}

int64_t date_to_num(int month, int64_t year) {
	int64_t dd = 1, sun = 0;
	int m;
	year -= 1900;
	if (year == -1) return 0;

	dd = cycle_day[year % 2800];
	sun = cycle_sun[year % 2800];

	int64_t ncycle = year/2800;
	sun += ncycle * cycle_sun[2800];

	for (m = 1; m < month; ++m) {
		sun += (dd % 7 == 0);
		dd += month_dates[m] + (m == 2 && is_leap(year+1900));
	}

	sun += (dd % 7 == 0);

	return sun;
}

int main()
{
	int T, y;

	calc_normal_sundays();
	calc_leap_sundays();
	calc_sunday_cycle();

	scanf("%d", &T);
	while (T--) {
		int d1, m1;
		int d2, m2;
		int64_t y1, y2, res;

		scanf("%" PRId64 " %d %d", &y1, &m1, &d1);
		scanf("%" PRId64 " %d %d", &y2, &m2, &d2);
		if (d1 == 1) {
			m1 -= 1;
			if (m1 == 0) {
				m1 = 12;
				y1 -= 1;
			}
		}
		res = date_to_num(m2, y2) - date_to_num(m1, y1);
		printf("%" PRId64 "\n", res);
	}

	return 0;
}
